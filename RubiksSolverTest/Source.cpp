#include <stdio.h>
#include "RCSIO.h"

//#include "Common.h"
//#include "CubePrinter.h"
//#include "CubeManager.h"
//#include "MoveManager.h"

void funcCallback(unsigned int x)
{
   printf("Num is %u\n", x);
}

int main()
{
   printf("Hello World! \n");

   RCSIO rcsio(funcCallback);
   funcCallback(4);
   //srand(0);
   //CubeType rubiks;
   //MoveSetType moveSet = { };

   //solveCube(&rubiks, ALGO_BEGINNER);
   return 0;

}