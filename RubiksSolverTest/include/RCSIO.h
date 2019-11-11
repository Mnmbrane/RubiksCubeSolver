#pragma once

#include "rapidjson/rapidjson.h"
#include <functional>

class RCSIO
{
public:
RCSIO(std::function<void(int)>);
~RCSIO();

void readCubeConfigJson(char*);

void solveCube();

private:
std::function<void(int)> Callback;
};