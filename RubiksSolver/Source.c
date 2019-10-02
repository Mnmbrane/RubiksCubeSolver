#include <stdio.h>
#include <time.h>
#include "Common.h"
#include "CubePrinter.h"
#include "CubeManager.h"
#include "MoveManager.h"


int main()
{
   srand(0);
   CubeType rubiks;
   MoveSetType moveSet = { 0 };

   initialize(&rubiks);

   mixCube(&rubiks, 20);

   printCube(rubiks);

   solveCube(rubiks, &moveSet, ALGO_BEGINNER);

}