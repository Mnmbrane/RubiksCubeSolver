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
   delete cube;
   cube = nullptr;
}

int RCSIO::readCubeSideLength(rapidjson::Document& cubeConfig)
{

}

void RCSIO::readCubeFace(const rapidjson::Value& allFaceConfig,
                         const char* member,
                         OrientationType orientation)
{
   // Check for "top", "down", "left", "right", "front", "back"
   assert(allFaceConfig.HasMember(member));

   // Set member
   const rapidjson::Value& faceConfig = allFaceConfig[member];

   // Make sure member is an array
   assert(faceConfig.IsArray());

   for (rapidjson::SizeType i = 0; i < faceConfig.Size(); i++)
   {
      
   }
}

void RCSIO::readCubeAllFaces(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("FaceConfig"));
   const rapidjson::Value& faceConfig = cubeConfig["FaceConfig"];

   readCubeFace(faceConfig, "top", ORIENTATION_TOP);
   readCubeFace(faceConfig, "down", ORIENTATION_DOWN);
   readCubeFace(faceConfig, "left", ORIENTATION_LEFT);
   readCubeFace(faceConfig, "right", ORIENTATION_RIGHT);
   readCubeFace(faceConfig, "front", ORIENTATION_FRONT);
   readCubeFace(faceConfig, "back", ORIENTATION_BACK);
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

   // Read Cube Side Length
   int cubeSideLength = readCubeSideLength(configDoc);

   // Create new cube
   cube = new Cube(cubeSideLength);

   // Read Cube Config
   readCubeAllFaces(configDoc);

   // Read Algorithm
   readCubeAlgorithm(configDoc);

   // Solve

}

