#include "CubeManager.h"
#include "MoveManager.h"
#include "BeginnerAlgo.h"
#include <stdlib.h>
#include <stdio.h>

void CubeManager::initialize()
{
   cube = new CubeType();

   // Assign an entire face only one square type

   // Top is yellow
   assignFaceColor(SQUARE_YELLOW, ORIENTATION_TOP);

   // Bottom is white
   assignFaceColor(SQUARE_WHITE, ORIENTATION_DOWN);

   // Left is red
   assignFaceColor(SQUARE_RED, ORIENTATION_LEFT);

   // Right is Orange
   assignFaceColor(SQUARE_ORANGE, ORIENTATION_RIGHT);

   // Front is Green
   assignFaceColor(SQUARE_GREEN, ORIENTATION_FRONT);

   // Back is Blue
   assignFaceColor(SQUARE_BLUE,  ORIENTATION_BACK);
}

void CubeManager::assignFaceColor( SquareType square, OrientationType orientation )
{
   // Loop through and assign a square type to an entire face
   for ( int i = 0; i < SIDE_LENGTH; i++ )
   {
      for ( int j = 0; j < SIDE_LENGTH; j++ )
      {
         cube->faces[orientation].squares[i][j] = square;
      }
   }
}

MoveSetType CubeManager::mixCube( int numMoves )
{
   MoveSetType retMoveSet = { };
   if ( (numMoves < 0 && numMoves > MAX_MOVES) || cube == nullptr )
   {  
      printf("Number of moves must be between 0 and %d\n", MAX_MOVES);
      return retMoveSet;
   }
   else if ( cube == nullptr )
   {
      printf("Cube must be initialized line(%d)\n", __LINE__);
      return retMoveSet;
   }
   else
   {
      // call randomeFace on each face
      for ( int i = 0; i < numMoves; i++ )
      {
         // Make a random move
         MoveType randMove = 
         { 
            (OrientationType) (rand() % MAX_ORIENTATION),
            (RotationType)    (rand() % MAX_ROATATION)
         };

         // Move the cube
         move(randMove, cube);

         // Save randome move to a set
         retMoveSet.moves[i] = randMove;
         retMoveSet.numMoves++;
      }
      return retMoveSet;
   }
}

MoveSetType CubeManager::solveCube( RubiksAlgorithmInterface algo )
{
   MoveSetType retMoveSet = { };

  retMoveSet = algo.solve(cube);

   return retMoveSet;
}

