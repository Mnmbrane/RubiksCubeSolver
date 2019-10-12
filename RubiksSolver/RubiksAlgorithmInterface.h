#pragma once
#include "Common.h"

class RubiksAlgorithmInterface
{
public:
   RubiksAlgorithmInterface();
   ~RubiksAlgorithmInterface();

   virtual MoveSetType solve(CubeType*);
private:
protected:
   CubeType* cube;
};

