#include <stdio.h>
#include "RCSIO.h"
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

   testing::InitGoogleTest(&argc, argv);

   return RUN_ALL_TESTS();

}