#pragma once

#include <functional>
#include <fstream>
#include <rapidjson/document.h>

class RCSIO
{
public:
RCSIO(std::function<void(int)>);
~RCSIO();

void readCubeConfigJson(std::ifstream&);

void solveCube();

private:
void readCubeFace(const rapidjson::Value&, const char*);
void readCubeAllFaces(rapidjson::Document&);
void readCubeAlgorithm(rapidjson::Document&);
std::function<void(int)> Callback;
};