#include "MoveManager.h"
#include <stdio.h>
#include <string.h>


typedef enum
{
   SQUARE_GROUP_TOP_ROW,
   SQUARE_GROUP_BOTTOM_ROW,
   SQUARE_GROUP_LEFT_COL,
   SQUARE_GROUP_RIGHT_COL
} SquareGroupType;

MoveManager::MoveManager(CubeType& inCube) :
   cube(inCube)
{ }

MoveManager::~MoveManager()
{

}

void MoveManager::rotateNormal(OrientationType orientation)
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

void MoveManager::rotatePrime(OrientationType orientation)
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
void MoveManager::rotateTwice(OrientationType orientation)
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
void MoveManager::rotate(RotationType rotation, OrientationType orientation)
{
   FaceType tempFace;

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      printf("ROTATING FACE NORMALLY\n");

      // Rotate the entire face
      rotateNormal(orientation);

      break;
   case ROTATION_PRIME:
      printf("ROTATING FACE PRIME\n");

      rotatePrime(orientation);
      break;
   case ROTATION_TWICE:
      printf("ROTATING FACE TWICE\n");

      rotateTwice(orientation);
      break;
   default:
      printf("ROTATION ERROR\n");
      break;
   }
   
}

// Switch 2 groups of squares
void transpose(SquareType* s1[SIDE_LENGTH], SquareType* s2[SIDE_LENGTH])
{
   int i;
   SquareType temp[SIDE_LENGTH];

   // Copy s1 to temp
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      temp[i] = *(s1[i]);
   }

   // Copy s2 to s1
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      *(s1[i]) = *(s2[i]);
   }

   // Copy back temp to s2
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      *(s2[i]) = temp[i];
   }
}

// Return a square grouping of based on the the orientation
void getSquareGroup(FaceType* face,
   SquareGroupType squareGroup,
   SquareType* outSquares[SIDE_LENGTH])
{
   switch ( squareGroup )
   {
   case SQUARE_GROUP_TOP_ROW:
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         outSquares[i] = &(face->squares[0][i]);
      }
      break;
   case SQUARE_GROUP_BOTTOM_ROW:
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         outSquares[i] = &(face->squares[SIDE_LENGTH - 1][i]);
      }
      break;
   case SQUARE_GROUP_LEFT_COL:
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         outSquares[i] = &(face->squares[i][0]);
      }
      break;
   case SQUARE_GROUP_RIGHT_COL:
      for ( int i = 0; i < SIDE_LENGTH; i++ )
      {
         outSquares[i] = &(face->squares[i][SIDE_LENGTH - 1]);
      }
      break;
   default:
      break;
   }
}

//// FUNCTION CALLBACKS
void MoveManager::top(RotationType rotation)
{
   // Adjacent squares
   SquareType* topFront[SIDE_LENGTH];
   SquareType* topRight[SIDE_LENGTH];
   SquareType* topBack[SIDE_LENGTH];
   SquareType* topLeft[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_FRONT]),
      SQUARE_GROUP_TOP_ROW,
      topFront);
   getSquareGroup(&(outCube->faces[ORIENTATION_RIGHT]),
      SQUARE_GROUP_TOP_ROW,
      topRight);
   getSquareGroup(&(outCube->faces[ORIENTATION_BACK]),
      SQUARE_GROUP_TOP_ROW,
      topBack);
   getSquareGroup(&(outCube->faces[ORIENTATION_LEFT]),
      SQUARE_GROUP_TOP_ROW,
      topLeft);

   // Rotate a face
   rotate(rotation, ORIENTATION_TOP);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      // Transpose the row of squares of adjacent faces
      transpose(topFront, topRight);
      transpose(topRight, topLeft);
      transpose(topRight, topBack);
      break;
   case ROTATION_PRIME:
      transpose(topFront, topLeft);
      transpose(topLeft, topRight);
      transpose(topLeft, topBack);
      break;
   case ROTATION_TWICE:
      transpose(topFront, topBack);
      transpose(topLeft, topRight);
      break;
   default:
      break;
   }

}

void MoveManager::down(RotationType rotation)
{
   // Adjacent squares
   SquareType* downFront[SIDE_LENGTH];
   SquareType* downRight[SIDE_LENGTH];
   SquareType* downBack[SIDE_LENGTH];
   SquareType* downLeft[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_FRONT]),
      SQUARE_GROUP_BOTTOM_ROW,
      downFront);
   getSquareGroup(&(outCube->faces[ORIENTATION_RIGHT]),
      SQUARE_GROUP_BOTTOM_ROW,
      downRight);
   getSquareGroup(&(outCube->faces[ORIENTATION_BACK]),
      SQUARE_GROUP_BOTTOM_ROW,
      downBack);
   getSquareGroup(&(outCube->faces[ORIENTATION_LEFT]),
      SQUARE_GROUP_BOTTOM_ROW,
      downLeft);

   // Rotate a face
   rotate(rotation, ORIENTATION_DOWN);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      transpose(downFront, downLeft);
      transpose(downRight, downLeft);
      transpose(downLeft, downBack);
      break;
   case ROTATION_PRIME:
      // Transpose the row of squares of adjacent faces
      transpose(downFront, downRight);
      transpose(downLeft, downRight);
      transpose(downRight, downBack);
      break;
   case ROTATION_TWICE:
      transpose(downFront, downBack);
      transpose(downLeft, downRight);
      break;
   default:
      break;
   }
}


void MoveManager::left(RotationType rotation)
{
   // Adjacent squares
   SquareType* leftFront[SIDE_LENGTH];
   SquareType* leftTop[SIDE_LENGTH];
   SquareType* leftBack[SIDE_LENGTH];
   SquareType* leftDown[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_FRONT]),
      SQUARE_GROUP_LEFT_COL,
      leftFront);
   getSquareGroup(&(outCube->faces[ORIENTATION_TOP]),
      SQUARE_GROUP_LEFT_COL,
      leftTop);
   getSquareGroup(&(outCube->faces[ORIENTATION_BACK]),
      SQUARE_GROUP_RIGHT_COL,
      leftBack);
   getSquareGroup(&(outCube->faces[ORIENTATION_DOWN]),
      SQUARE_GROUP_LEFT_COL,
      leftDown);

   // Rotate a face
   rotate(rotation, ORIENTATION_LEFT);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      transpose(leftTop, leftFront);
      transpose(leftTop, leftDown);
      transpose(leftTop, leftBack);
      break;
   case ROTATION_PRIME:
      // Transpose the row of squares of adjacent faces
      transpose(leftDown, leftFront);
      transpose(leftDown, leftTop);
      transpose(leftDown, leftBack);
      break;
   case ROTATION_TWICE:
      transpose(leftFront, leftBack);
      transpose(leftTop, leftDown);
      break;
   default:
      break;
   }
}

void MoveManager::right(RotationType rotation)
{
   // Adjacent squares
   SquareType* rightFront[SIDE_LENGTH];
   SquareType* rightTop[SIDE_LENGTH];
   SquareType* rightBack[SIDE_LENGTH];
   SquareType* rightDown[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_FRONT]),
      SQUARE_GROUP_RIGHT_COL,
      rightFront);
   getSquareGroup(&(outCube->faces[ORIENTATION_TOP]),
      SQUARE_GROUP_RIGHT_COL,
      rightTop);
   getSquareGroup(&(outCube->faces[ORIENTATION_BACK]),
      SQUARE_GROUP_LEFT_COL,
      rightBack);
   getSquareGroup(&(outCube->faces[ORIENTATION_DOWN]),
      SQUARE_GROUP_RIGHT_COL,
      rightDown);

   // Rotate a face
   rotate(rotation, ORIENTATION_RIGHT);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      transpose(rightDown, rightFront);
      transpose(rightDown, rightTop);
      transpose(rightDown, rightBack);
      break;
   case ROTATION_PRIME:
      // Transpose the row of squares of adjacent faces
      transpose(rightTop, rightFront);
      transpose(rightTop, rightDown);
      transpose(rightTop, rightBack);
      break;
   case ROTATION_TWICE:
      transpose(rightFront, rightBack);
      transpose(rightTop, rightDown);
      break;
   default:
      break;
   }
}

void MoveManager::front(RotationType rotation)
{
   // Adjacent squares
   SquareType* frontRight[SIDE_LENGTH];
   SquareType* frontLeft[SIDE_LENGTH];
   SquareType* frontTop[SIDE_LENGTH];
   SquareType* frontDown[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_RIGHT]),
      SQUARE_GROUP_LEFT_COL,
      frontRight);
   getSquareGroup(&(outCube->faces[ORIENTATION_LEFT]),
      SQUARE_GROUP_RIGHT_COL,
      frontLeft);
   getSquareGroup(&(outCube->faces[ORIENTATION_TOP]),
      SQUARE_GROUP_BOTTOM_ROW,
      frontTop);
   getSquareGroup(&(outCube->faces[ORIENTATION_DOWN]),
      SQUARE_GROUP_TOP_ROW,
      frontDown);

   // Rotate a face
   rotate(rotation, ORIENTATION_FRONT);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      transpose(frontLeft, frontTop);
      transpose(frontLeft, frontRight);
      transpose(frontLeft, frontDown);
      break;
   case ROTATION_PRIME:
      // Transpose the row of squares of adjacent faces
      transpose(frontRight, frontTop);
      transpose(frontRight, frontLeft);
      transpose(frontRight, frontDown);
      break;
   case ROTATION_TWICE:
      transpose(frontRight, frontLeft);
      transpose(frontTop, frontDown);
      break;
   default:
      break;
   }
}

void MoveManager::back(RotationType rotation)
{
   // Adjacent squares
   SquareType* backRight[SIDE_LENGTH];
   SquareType* backLeft[SIDE_LENGTH];
   SquareType* backTop[SIDE_LENGTH];
   SquareType* backDown[SIDE_LENGTH];


   getSquareGroup(&(outCube->faces[ORIENTATION_RIGHT]),
      SQUARE_GROUP_RIGHT_COL,
      backRight);
   getSquareGroup(&(outCube->faces[ORIENTATION_LEFT]),
      SQUARE_GROUP_LEFT_COL,
      backLeft);
   getSquareGroup(&(outCube->faces[ORIENTATION_TOP]),
      SQUARE_GROUP_TOP_ROW,
      backTop);
   getSquareGroup(&(outCube->faces[ORIENTATION_DOWN]),
      SQUARE_GROUP_BOTTOM_ROW,
      backDown);

   // Rotate a face
   rotate(rotation, ORIENTATION_BACK);

   switch ( rotation )
   {
   case ROTATION_NORMAL:
      transpose(backRight, backTop);
      transpose(backRight, backLeft);
      transpose(backRight, backDown);
      break;
   case ROTATION_PRIME:
      // Transpose the row of squares of adjacent faces
      transpose(backLeft, backTop);
      transpose(backLeft, backRight);
      transpose(backLeft, backDown);
      break;
   case ROTATION_TWICE:
      transpose(backLeft, backRight);
      transpose(backTop, backDown);
      break;
   default:
      break;
   }
}


// Main move function
void move(MoveType move, CubeType* cube)
{
   funcMove[move.orientation](move.rotation, cube);
}