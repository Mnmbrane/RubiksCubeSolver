#include "CubeFace.h"


CubeFace::CubeFace()
{

}
CubeFace::CubeFace(int sideLength, SquareType initColor) :
   maxSideLength(sideLength)
{
   // Initalize rows
   cubeFace = new SquareType*[maxSideLength];

   // Initialize columns
   for(int i = 0; i < maxSideLength; ++i)
   {
      cubeFace[i] = new SquareType[maxSideLength];
   }

   // Initialize face with a specific color
   initFaceColor(initColor);
}

CubeFace::~CubeFace()
{
   for(int i = 0; i < maxSideLength; ++i)
   {
      delete[] cubeFace[i];
   }

   delete[] cubeFace;
}

void CubeFace::initFaceColor(SquareType initColor)
{
   for(int i = 0; i < maxSideLength; ++i)
   {
      for(int j = 0; j < maxSideLength; ++j)
      {
         cubeFace[i][j] = initColor;
      }
   }
}