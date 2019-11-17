#include <stdio.h>
#include "RCSIO.h"
#include "Cube.h"
#include <gtest/gtest.h>

struct BankAccount
{
   int balance;

   BankAccount()
   {

   }

   explicit BankAccount(const int balance)
      : balance(balance)
   {
   }
};

TEST(AccountTest, BankAccountStartsEmpty)
{
   BankAccount account(0);
   EXPECT_EQ(0, account.balance);
}

int main(int argc, char* argv[])
{
   printf("Hello World! \n");

   Cube cube(3);

   CubeFace cubeFace = cube.getFace(ORIENTATION_BACK);
   SquareType** face = cubeFace.getFace();

   SquareType testFace[3][3];

   for(int i = 0; i < 3; i++)
   {
      for(int j = 0; j < 3; j++)
      {
         testFace[i][j] = face[i][j];
         printf("%d ", testFace[i][j]);
      }
      printf("\n");
   }

   testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();

}