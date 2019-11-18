#ifndef _COMMON_H_
#define _COMMON_H_

#define SIDE_LENGTH 3
#define MAX_MOVES 200
#define MAX_ADJ_ORIENTATION 4
#define MAX_POSSIBLE_MOVETYPES (MAX_ORIENTATION * MAX_ROATATION)

typedef enum
{
   SQUARE_GROUP_TOP_ROW,
   SQUARE_GROUP_BOTTOM_ROW,
   SQUARE_GROUP_LEFT_COL,
   SQUARE_GROUP_RIGHT_COL
} SquareGroupType;

typedef enum
{
   ROTATION_NORMAL,
   ROTATION_PRIME,
   ROTATION_TWICE,

   MAX_ROATATION
} RotationType;

typedef enum
{
   ALGO_BEGINNER,
   ALGO_CFOP
} AlgorithmType;

typedef struct
{
   OrientationType orientation;
   RotationType rotation;
} MoveType;

typedef struct
{
   MoveType moves[MAX_MOVES];
   int numMoves;
} MoveSetType;


#endif