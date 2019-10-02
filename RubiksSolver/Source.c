#include <stdio.h>
#include <time.h>
#include "Common.h"
#include "CubePrinter.h"
#include "CubeManager.h"
#include "MoveManager.h"


int main()
{
   srand(time(0));
   CubeType rubiks;
   MoveSetType moveSet = 
   { { {ORIENTATION_BACK, ROTATION_NORMAL},
       {ORIENTATION_BACK, ROTATION_PRIME},
       {ORIENTATION_BACK, ROTATION_TWICE} }, 3 };

   initialize(&rubiks);

   solveCube(rubiks, &moveSet, ALGO_BEGINNER);

}