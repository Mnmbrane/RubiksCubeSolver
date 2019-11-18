#pragma once

#include <functional>
#include <fstream>
#include <rapidjson/document.h>
#include "Cube.h"


class RCSIO
{
public:
RCSIO(std::function<void(int)>);
~RCSIO();

void readCubeConfigJson(std::ifstream&);
void solveCube();

private:
int readCubeSideLength(rapidjson::Document&);
void readCubeFace(const rapidjson::Value&,
                  const char*,
                  OrientationType);
void readCubeAllFaces(rapidjson::Document&);
void readCubeAlgorithm(rapidjson::Document&);
std::function<void(int)> Callback;

Cube* cube;
};