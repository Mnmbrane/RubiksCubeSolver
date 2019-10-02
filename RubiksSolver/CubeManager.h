#pragma once
#include "Common.h"

// Assign color to each face
void initialize(CubeType* cube);

// Mix up the cube
bool mixCube(CubeType* outCube, int numMoves);

// Solve Cube
void solveCube(CubeType cube, MoveSetType* outMoveSet, AlgorithmType algo);