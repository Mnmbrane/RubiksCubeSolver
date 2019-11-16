#include "Cube.h"

Cube::Cube(int maxSideLength)
{
   cubeFace = new CubeFace[MAX_ORIENTATION];
}

Cube::~Cube()
{

}
