#pragma once
#include "Common.h"
#include "RubiksAlgorithmInterface.h"


class BeginnerAlgorithm : public RubiksAlgorithmInterface
{
public:
   MoveSetType solve(CubeType* cube);
private:
};
