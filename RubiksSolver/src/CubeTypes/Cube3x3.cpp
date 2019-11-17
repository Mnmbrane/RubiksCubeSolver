#include "Cube3x3.h"
#include <string.h>

void Cube3x3::rotateNormal(OrientationType orientation)
{
   FaceType tempFace;
   
   // Rotate the entire face
   for ( int j = SIDE_LENGTH - 1; j >= 0; j-- )
   {
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         tempFace.squares[i][j] = cube.faces[orientation].squares[(SIDE_LENGTH - 1) - j][i];
      }
   }
   memcpy(cube.faces[orientation].squares,
          tempFace.squares,
          sizeof(cube.faces[orientation].squares));
}

void Cube3x3::rotatePrime(OrientationType orientation)
{
   FaceType tempFace;
   
   // Rotate the entire face
   for ( int j = SIDE_LENGTH - 1; j >= 0; j-- )
   {
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         tempFace.squares[i][j] = cube.faces[orientation].squares[j][(SIDE_LENGTH - 1) - i];
      }
   }
   memcpy(cube.faces[orientation].squares,
          tempFace.squares,
          sizeof(cube.faces[orientation].squares));
}
void Cube3x3::rotateTwice(OrientationType orientation)
{
   FaceType tempFace;
   
   // Rotate the entire face
   for ( int j = SIDE_LENGTH - 1; j >= 0; j-- )
   {
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         tempFace.squares[i][j] = cube.faces[orientation].squares[(SIDE_LENGTH - 1) - i][(SIDE_LENGTH - 1) - j];
      }
   }
   memcpy(cube.faces[orientation].squares,
          tempFace.squares,
          sizeof(cube.faces[orientation].squares));
}

// Rotate a face Clockwise
void Cube3x3::rotate(RotationType rotation, OrientationType orientation)
{
   FaceType tempFace;

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      // Rotate the entire face
      rotateNormal(orientation);
      break;
   case ROTATION_PRIME:
      rotatePrime(orientation);
      break;
   case ROTATION_TWICE:
      rotateTwice(orientation);
      break;
   default:
      break;
   }
   
}