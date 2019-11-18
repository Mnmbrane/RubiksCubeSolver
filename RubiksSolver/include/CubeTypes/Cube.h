#pragma once

#include "CubeFace.h"

typedef enum
{
   ORIENTATION_TOP,
   ORIENTATION_DOWN,
   ORIENTATION_LEFT,
   ORIENTATION_RIGHT,
   ORIENTATION_FRONT,
   ORIENTATION_BACK,

   MAX_ORIENTATION
} OrientationType;


class Cube
{
public:
Cube(const int);
~Cube();

virtual CubeFace getFace(OrientationType) const;
virtual void setSquare(OrientationType,
                       SquareType,
                       int, int);


private:
CubeFace* cubeFace;
};