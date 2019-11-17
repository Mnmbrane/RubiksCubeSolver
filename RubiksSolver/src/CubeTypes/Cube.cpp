#include "Cube.h"

Cube::Cube(int maxSideLength)
{
   cubeFace = new CubeFace[MAX_ORIENTATION]
   {
      CubeFace(maxSideLength, SQUARE_WHITE),    // ORIENTATION_TOP
      CubeFace(maxSideLength, SQUARE_YELLOW),   // ORIENTATION_DOWN
      CubeFace(maxSideLength, SQUARE_BLUE),     // ORIENTATION_LEFT
      CubeFace(maxSideLength, SQUARE_GREEN),    // ORIENTATION_RIGHT
      CubeFace(maxSideLength, SQUARE_RED),      // ORIENTATION_FRONT
      CubeFace(maxSideLength, SQUARE_ORANGE),   // ORIENTATION_BACK
   };
}

Cube::~Cube()
{
   delete[] cubeFace;
}

CubeFace Cube::getFace(OrientationType orientation) const
{
   return cubeFace[orientation];
}