#pragma once

// Color for each square
typedef enum
{
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

SquareType** getFace() const;

private:
void initFaceColor(SquareType);

SquareType** cubeFace;
int maxSideLength;
};