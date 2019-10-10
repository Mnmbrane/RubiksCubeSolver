#include "CubeManager.h"
#include "MoveManager.h"
#include "BeginnerAlgo.h"
#include <stdlib.h>

void assignFaceColor(SquareType, FaceType*);

void initialize(CubeType* outCube)
{
   // Assign an entire face only one square type

   // Top is yellow
   assignFaceColor(SQUARE_YELLOW, getFace(outCube, ORIENTATION_TOP));

   // Bottom is white
   assignFaceColor(SQUARE_WHITE, getFace(outCube, ORIENTATION_DOWN));

   // Left is red
   assignFaceColor(SQUARE_RED, getFace(outCube, ORIENTATION_LEFT));

   // Right is Orange
   assignFaceColor(SQUARE_ORANGE, getFace(outCube, ORIENTATION_RIGHT));

   // Front is Green
   assignFaceColor(SQUARE_GREEN, getFace(outCube, ORIENTATION_FRONT));

   // Back is Blue
   assignFaceColor(SQUARE_BLUE, getFace(outCube, ORIENTATION_BACK));
}

void assignFaceColor(SquareType square, FaceType* outFace)
{
   int i, j;

   // Loop through and assign a square type to an entire face
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      for ( j = 0; j < SIDE_LENGTH; j++ )
      {
         outFace->squares[i][j] = square;
      }
   }
}

FaceType* getFace(CubeType* cube, OrientationType orientation)
{
   return &(cube->faces[orientation]);
}

MoveSetType mixCube(CubeType* outCube, int numMoves)
{
   MoveSetType retMoveSet = { };
   if ( (numMoves < 0 && numMoves > MAX_MOVES) || outCube == NULL )
   {
      return retMoveSet;
   }
   else
   {
      int i;
      // call randomeFace on each face
      for ( i = 0; i < numMoves; i++ )
      {
         MoveType randMove = 
         { 
            (OrientationType) (rand() % MAX_ORIENTATION),
            (RotationType)    (rand() % MAX_ROATATION)
         };

         move(randMove, outCube);

         retMoveSet.moves[i] = randMove;
         retMoveSet.numMoves++;
      }
      return retMoveSet;
   }
}

MoveSetType solveCube(CubeType cube, AlgorithmType algo)
{
   MoveSetType retMoveSet = { };
   switch ( algo )
   {
   case ALGO_BEGINNER:
      retMoveSet = beginnerSolve(cube);
      break;
   case ALGO_CFOP:
      break;
   default:
      break;
   }
   return retMoveSet;
}