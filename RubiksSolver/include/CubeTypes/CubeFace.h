#pragma once

// Color for each square
typedef enum
{
   SQUARE_INVALID = -1,
   SQUARE_WHITE,
   SQUARE_YELLOW,
   SQUARE_RED,
   SQUARE_ORANGE,
   SQUARE_GREEN,
   SQUARE_BLUE,

   MAX_SQUARE
} SquareType;


class CubeFace
{
public:
CubeFace();
CubeFace(int, SquareType);
~CubeFace();

SquareType getSquare(int, int);
void setSquare(SquareType, int, int);

private:
void initFaceColor(SquareType);

SquareType** cubeFace;
int maxSideLength;
};