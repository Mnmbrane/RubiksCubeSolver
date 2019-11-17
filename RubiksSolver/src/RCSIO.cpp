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

void RCSIO::readCubeFace(const rapidjson::Value& allFaceConfig, const char* member)
{
   assert(allFaceConfig.HasMember(member));
   const rapidjson::Value& faceConfig = allFaceConfig[member];
   assert(faceConfig.IsArray());

   for (rapidjson::SizeType i = 0; i < faceConfig.Size(); i++)
   {
      printf("%s[%d] = %s\n", member, i, faceConfig[i].GetString());
   }
}

void RCSIO::readCubeAllFaces(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("FaceConfig"));
   const rapidjson::Value& faceConfig = cubeConfig["FaceConfig"];

   readCubeFace(faceConfig, "top");
   readCubeFace(faceConfig, "down");
   readCubeFace(faceConfig, "left");
   readCubeFace(faceConfig, "right");
   readCubeFace(faceConfig, "front");
   readCubeFace(faceConfig, "back");
}

void RCSIO::readCubeAlgorithm(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("Algorithm"));
   const rapidjson::Value& algorithmJson = cubeConfig["Algorithm"];

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
   readCubeAllFaces(configDoc);

   // Read Algorithm
   readCubeAlgorithm(configDoc);

   // Solve

}

