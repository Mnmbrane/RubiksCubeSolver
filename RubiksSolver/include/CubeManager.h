#pragma once

#include "CubeTypes/Cube.h"

static const int DEFAULT_SIDE_LENGTH = 3;

class CubeManager
{
public:
   CubeManager();
   ~CubeManager();
   
   void SetSideLength(int);
   void SetSquare(OrientationType, SquareType, int, int);

private:
   Cube* cube;
};

