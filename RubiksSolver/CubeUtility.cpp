#include "CubeUtility.h"
#include "string.h"

MoveSetType addMoveSets(MoveSetType moveSet1, MoveSetType moveSet2)
{
   MoveSetType retMoveSet = {  };
   retMoveSet.numMoves = moveSet1.numMoves + moveSet2.numMoves;
   memcpy(retMoveSet.moves, moveSet1.moves, moveSet1.numMoves);

   memcpy(&(retMoveSet.moves[moveSet1.numMoves]), moveSet2.moves, moveSet2.numMoves);

   return retMoveSet;
}