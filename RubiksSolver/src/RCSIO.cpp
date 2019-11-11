#include "RCSIO.h"
#include "Common.h"
#include "rapidjson/document.h"

using namespace rapidjson;


RCSIO::RCSIO(std::function<void(int)> inCallback)
{
   Callback = inCallback;

   Callback(3);
}
RCSIO::~RCSIO()
{

}

void RCSIO::readCubeConfigJson(char* configJson)
{
   // Translate JSON to Cube Config
   Document configDoc;
   configDoc.Parse(configJson);

   
}

