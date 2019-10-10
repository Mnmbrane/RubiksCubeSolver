#pragma once
#include "Common.h"

// Assign color to each face
void initialize(CubeType*);

// Mix up the cube
MoveSetType mixCube(CubeType*, int);

// Solve Cube
MoveSetType solveCube(CubeType*, AlgorithmType);

FaceType* getFace(CubeType*, OrientationType);