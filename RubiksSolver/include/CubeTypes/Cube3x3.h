#pragma once

#include "Common.h"
#include "Cube.h"

class Cube3x3 : public Cube
{
public:
   typedef enum
   {
      ROTATION_NORMAL,
      ROTATION_PRIME,
      ROTATION_TWICE,

      MAX_ROATATION
   } RotationType;
   
   Cube3x3();
   ~Cube3x3();
   void rotate(RotationType, OrientationType);
private:

   void rotateNormal(OrientationType);
   void rotatePrime(OrientationType);
   void rotateTwice(OrientationType);
   void transpose();
   
};