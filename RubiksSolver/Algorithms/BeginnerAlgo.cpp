#include "BeginnerAlgo.h"
#include <stdio.h>
#include <string.h>

MoveSetType solveBottomCross();
MoveSetType solveCorners();
MoveSetType solveSecondLayer();
MoveSetType solveTopCross();
MoveSetType solveTopEdges();
MoveSetType permutateCorners();
MoveSetType orientCorners();

MoveSetType BeginnerAlgorithm::solve(CubeType* inCube)
{
   MoveSetType moveset = { };
   cube = inCube;
   
   printf("Beginner Solve\n");
   return moveset;
}