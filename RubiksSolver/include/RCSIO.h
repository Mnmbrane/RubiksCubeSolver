#pragma once

#include <functional>
#include <fstream>
#include <string>
#include <rapidjson/document.h>
#include "Cube.h"
#include "CubeManager.h"


class RCSIO
{
public:
RCSIO(std::function<void(int)>);
~RCSIO();

void readCubeConfigJson(std::ifstream&);
void solveCube();

private:
SquareType getSquareFromString(std::string);
void readCubeSideLength(rapidjson::Document&);
void readCubeFace(const rapidjson::Value&,
                  const char*,
                  OrientationType);
void readCubeAllFaces(rapidjson::Document&);
void readCubeAlgorithm(rapidjson::Document&);

CubeManager                 cubeManager;
std::function<void(int)>    Callback;
unsigned int                cubeSideLength;
};