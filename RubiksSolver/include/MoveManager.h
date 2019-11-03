#pragma once
#include "Common.h"

class MoveManager
{
public:
   MoveManager(CubeType&);
   ~MoveManager();

   void move(MoveType);
private:

   // Moves on Cube
   void top(RotationType);
   void down(RotationType);
   void left(RotationType);
   void right(RotationType);
   void front(RotationType);
   void back(RotationType);

   CubeType& cube;
};