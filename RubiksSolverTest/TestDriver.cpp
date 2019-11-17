#include <stdio.h>
#include "RCSIO.h"
#include "CubeTest.h"
#include <gtest/gtest.h>
#include <fstream>

using namespace std;

void solveCallback(int num)
{
   printf("%d\n", num);
}
int main(int argc, char* argv[])
{
   ifstream configFile("RubiksSolverTest/JsonCubeConfigs/example.json");

   printf("Starting Rubiks Cube Test \n");

   RCSIO rcsio(solveCallback);

   rcsio.readCubeConfigJson(configFile);

   configFile.close();

   testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();

}