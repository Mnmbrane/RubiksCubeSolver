#include "RCSIO.h"
#include <rapidjson/istreamwrapper.h>

RCSIO::RCSIO(std::function<void(int)> inCallback) :
   cubeManager(),
   Callback(inCallback),
   cubeSideLength(DEFAULT_SIDE_LENGTH)
{
   Callback(3);
}

RCSIO::~RCSIO()
{;
}

void RCSIO::solveCube()
{

}

SquareType RCSIO::getSquareFromString(std::string squareString)
{
   SquareType retSquare;
   if(squareString.compare("y") == 0)
   {
      retSquare = SQUARE_YELLOW;
   }
   else if(squareString.compare("w") == 0)
   {
      retSquare = SQUARE_WHITE;
   }
   else if(squareString.compare("b") == 0)
   {
      retSquare = SQUARE_BLUE;
   }
   else if(squareString.compare("g") == 0)
   {
      retSquare = SQUARE_GREEN;
   }
   else if(squareString.compare("r") == 0)
   {
      retSquare = SQUARE_RED;
   }
   else if(squareString.compare("o") == 0)
   {
      retSquare = SQUARE_ORANGE;
   }
   else
   {
      retSquare = SQUARE_INVALID;
   }
   
   assert(retSquare != SQUARE_INVALID);
   return retSquare;
}

void RCSIO::readCubeSideLength(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("CubeSize"));
   const rapidjson::Value& sideLength = cubeConfig["CubeSize"];

   assert(sideLength.IsUint());

   cubeSideLength = sideLength.GetUint();
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

   // Set the Cube faces
   for (rapidjson::SizeType i = 0; i < faceConfig.Size(); i++)
   {
      // 0, 1, 2 row 0
      // 3, 4, 5 row 1
      // 6, 7, 8 row 2
      int row = i / cubeSideLength;
      int col = i % cubeSideLength;
      cubeManager.SetSquare(orientation,
                            getSquareFromString(faceConfig[i].GetString()),
                            row,
                            col);
   }
}

void RCSIO::readCubeAllFaces(rapidjson::Document& cubeConfig)
{
   assert(cubeConfig.HasMember("FaceConfig"));
   const rapidjson::Value& faceConfig = cubeConfig["FaceConfig"];

   readCubeFace(faceConfig, "top",     ORIENTATION_TOP);
   readCubeFace(faceConfig, "down",    ORIENTATION_DOWN);
   readCubeFace(faceConfig, "left",    ORIENTATION_LEFT);
   readCubeFace(faceConfig, "right",   ORIENTATION_RIGHT);
   readCubeFace(faceConfig, "front",   ORIENTATION_FRONT);
   readCubeFace(faceConfig, "back",    ORIENTATION_BACK);
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
   readCubeSideLength(configDoc);

   // Read Cube Config
   readCubeAllFaces(configDoc);

   // Read Algorithm
   readCubeAlgorithm(configDoc);
}

