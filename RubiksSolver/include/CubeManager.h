#pragma once
#include "Common.h"
#include "RubiksAlgorithmInterface.h"

class CubeManager
{
public:
   // Assign color to each face
   void initialize();

   // Mix up the cube
   MoveSetType mixCube(int);

   // Solve Cube
   MoveSetType solveCube(RubiksAlgorithmInterface);

   // Get Cube
   CubeType getCube();


private:

   void assignFaceColor(SquareType, OrientationType);

   CubeType* cube;
};

