#pragma once
#include "Common.h"

// Assign color to each face
void initialize(CubeType* cube);

// Mix up the cube
void mixCube(CubeType* outCube);

// Solve Cube
void solveCube(CubeType cube, MoveSetType* outMoveSet, AlgorithmType algo);