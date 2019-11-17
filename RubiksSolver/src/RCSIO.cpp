#include "RCSIO.h"
#include "Common.h"
#include <rapidjson/istreamwrapper.h>

RCSIO::RCSIO(std::function<void(int)> inCallback)
{
   Callback = inCallback;

   Callback(3);
}
RCSIO::~RCSIO()
{

}
void RCSIO::readCubeFaces(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("FaceConfig"));
   const rapidjson::Value& faceConfig = cubeConfig["FaceConfig"];

   assert(faceConfig.HasMember("top"));
   assert(faceConfig.HasMember("down"));
   assert(faceConfig.HasMember("left"));
   assert(faceConfig.HasMember("right"));
   assert(faceConfig.HasMember("front"));
   assert(faceConfig.HasMember("back"));
}

void RCSIO::readCubeAlgorithm(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("algorithm"));
   const rapidjson::Value& algorithmJson = cubeConfig["algorithm"];

   assert(algorithmJson.IsString());

   printf("%s\n", algorithmJson.GetString());
}

void RCSIO::readCubeConfigJson(std::ifstream& configJson)
{
   rapidjson::IStreamWrapper configJsonStreamWrapper(configJson);
   // Translate JSON to Cube Config
   rapidjson::Document configDoc;
   configDoc.ParseStream(configJsonStreamWrapper);

   // Read Cube Config
   readCubeFaces(configDoc);

   // Read Algorithm
   readCubeAlgorithm(configDoc);

   // Solve

}

