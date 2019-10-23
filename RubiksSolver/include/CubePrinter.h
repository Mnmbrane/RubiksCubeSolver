#pragma once

#include "Common.h"

#ifdef _WIN32
#include <Windows.h>
#endif

// Print the entire cube 
void printCube(CubeType cube);

// Print the face
void printFace(FaceType face);