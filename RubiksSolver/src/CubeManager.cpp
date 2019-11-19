#include "CubeManager.h"
#include <stdlib.h>
#include <stdio.h>

CubeManager::CubeManager()
{
   cube = new Cube(DEFAULT_SIDE_LENGTH);
}

CubeManager::~CubeManager()
{
   delete cube;
   cube = nullptr;
}

void CubeManager::SetSideLength(int sideLength)
{
   if(sideLength != DEFAULT_SIDE_LENGTH)
   {
      // Destroy cube
      delete cube;

      // Create new cube with new side length
      cube = new Cube(sideLength);
   }
   else
   {
      // keep current configuration
   }
   
}

void CubeManager::SetSquare(OrientationType orientation, SquareType square, int row, int col)
{
   cube->setSquare(orientation, square, row, col);
}