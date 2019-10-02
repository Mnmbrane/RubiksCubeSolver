#include "CubeManager.h"
#include "MoveManager.h"
#include "BeginnerAlgo.h"

void randomScramble(FaceType*);
void assignFaceColor(SquareType, FaceType*);

void initialize(CubeType* outCube)
{
   // Assign an entire face only one square type

   // Top is yellow
   assignFaceColor(SQUARE_YELLOW, &(outCube->faces[ORIENTATION_TOP]));

   // Bottom is white
   assignFaceColor(SQUARE_WHITE, &(outCube->faces[ORIENTATION_DOWN]));

   // Left is red
   assignFaceColor(SQUARE_RED, &(outCube->faces[ORIENTATION_LEFT]));

   // Right is Orange
   assignFaceColor(SQUARE_ORANGE, &(outCube->faces[ORIENTATION_RIGHT]));

   // Front is Green
   assignFaceColor(SQUARE_GREEN, &(outCube->faces[ORIENTATION_FRONT]));

   // Back is Blue
   assignFaceColor(SQUARE_BLUE, &(outCube->faces[ORIENTATION_BACK]));
}

void assignFaceColor(SquareType square,
                     FaceType* outFace)
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

void randomScramble(FaceType* outFace)
{
   int i, j;

   // Loop through and assign a randome square type to
   // the squares in each faces
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      for ( j = 0; j < SIDE_LENGTH; j++ )
      {
         outFace->squares[i][j] = rand() % MAX_SQUARE;
      }
   }
}

void mixCube(CubeType* outCube)
{
   int i;

   // call randomeFace on each face
   for ( i = 0; i < MAX_ORIENTATION; i++ )
   {
      randomScramble(&(outCube->faces[i]));
   }
}

void solveCube(CubeType cube, MoveSetType* outMoveSet, AlgorithmType algo)
{
   switch ( algo )
   {
   case ALGO_BEGINNER:
      *outMoveSet = beginnerSolve(cube);
      break;
   case ALGO_CFOP:
      break;
   default:
      break;
   }
}