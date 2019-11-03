#pragma once

#include "Common.h"

class Rotate
{
public:
   typedef enum
   {
      ROTATION_NORMAL,
      ROTATION_PRIME,
      ROTATION_TWICE,

      MAX_ROATATION
   } RotationType;
   
   Rotate();
   ~Rotate();
   void rotate(RotationType, OrientationType);
private:
   void rotateNormal(OrientationType);
   void rotatePrime(OrientationType);
   void rotateTwice(OrientationType);
   void transpose();
   CubeType& cube;
};