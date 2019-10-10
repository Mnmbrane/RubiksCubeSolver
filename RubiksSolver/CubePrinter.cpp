#pragma once
#include <stdio.h>
#include "CubePrinter.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#define WHITE 240
#define YELLOW 224
#define RED 71
#define ORANGE 192
#define GREEN 160
#define BLUE 159
#define NORM 15


#ifdef _WIN32
#define SET_CONSOLE_COLOR(x) (SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x))
#else
#define SETCONSOLECOLOR(X) 
#endif // _WIN32

void setConsoleColor(SquareType square)
{
   switch ( square )
   {
   case SQUARE_WHITE:
      SET_CONSOLE_COLOR(WHITE);
      break;
   case SQUARE_YELLOW:
      SET_CONSOLE_COLOR(YELLOW);
      break;
   case SQUARE_RED:
      SET_CONSOLE_COLOR(RED);
      break;
   case SQUARE_ORANGE:
      SET_CONSOLE_COLOR(ORANGE);
      break;
   case SQUARE_GREEN:
      SET_CONSOLE_COLOR(GREEN);
      break;
   case SQUARE_BLUE:
      SET_CONSOLE_COLOR(BLUE);
      break;
   default:
      SET_CONSOLE_COLOR(NORM);
      break;
   }
}

char getColorCharacter(SquareType square)
{
   char retChar;
   switch ( square )
   {
   case SQUARE_WHITE:
      retChar = 'W';
      break;
   case SQUARE_YELLOW:
      retChar = 'Y';
      break;
   case SQUARE_RED:
      retChar = 'R';
      break;
   case SQUARE_ORANGE:
      retChar = 'O';
      break;
   case SQUARE_GREEN:
      retChar = 'G';
      break;
   case SQUARE_BLUE:
      retChar = 'B';
      break;
   default:
      retChar = '*';
      break;
   }
   return retChar;
}

void printColorChar(SquareType square)
{
   // Change console color
   setConsoleColor(square);
   // Print the color
   printf("%c", getColorCharacter(square));
   // Set Console back to normal
   SET_CONSOLE_COLOR(NORM);

}

// Print one side of the cube
void printFace(FaceType face)
{
   int i, j;

   // print the color of the squares
   for ( i = 0; i < SIDE_LENGTH; i++ )
   {
      for ( j = 0; j < SIDE_LENGTH; j++ )
      {
         printColorChar(face.squares[i][j]);
         printf(" ");
      }
      printf("\n");
   }
}

void printOrientation(OrientationType orientation)
{
   switch ( orientation )
   {
   case ORIENTATION_TOP:
      printf("TOP");
      break;
   case ORIENTATION_DOWN:
      printf("BOTTOM");
      break;
   case ORIENTATION_LEFT:
      printf("LEFT");
      break;
   case ORIENTATION_RIGHT:
      printf("RIGHT");
      break;
   case ORIENTATION_FRONT:
      printf("FRONT");
      break;
   case ORIENTATION_BACK:
      printf("BACK");
      break;
   default:
      printf("ERROR");
      break;
   }
}

// Print the entire cube 
void printCube(CubeType cube)
{
   int i;
   
   for ( i = 0; i < MAX_ORIENTATION; i++ )
   {
      printOrientation((OrientationType)i);
      printf(":\n");
      printFace(cube.faces[i]);
   }

}