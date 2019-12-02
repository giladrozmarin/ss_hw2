#include <stdio.h>
#include "myBank.h"
#include <stdbool.h>

bool   on = true;
char input;

int main()
{
    InitStart();

    while (on)
    {
        char input;
        printf("Transaction type?\n");
        scanf(" %c", &input);
        
        if(input == 'O'){
            double amount;
            printf("Please insert amount \n");
            if(!CheckAmount(amount, scanf("%lf", &amount)));
            else OpenBankAccount(amount);
        }
   
        else if(input == 'B'){
           int account;
           printf("Please insert account number \n");
           scanf("%d", &account);
           if(CheckAccount(account))
           printf("your balance is %.2f \n",BalanceCheckAccount(account));
        }

        else if(input == 'D'){
           int account;
           printf("Please insert account number \n");
           scanf("%d", &account);
           if(CheckAccount(account))
            {
            double amount;
            printf("Please insert amount \n");
            if(!CheckAmount(amount, scanf("%lf", &amount)));
            else printf("your new balance is %.2f \n",Deposit(account,amount));
            }
        }
        
        else if(input == 'W'){
           int account;
           printf("Please insert account number \n");
           scanf("%d", &account);
           if(CheckAccount(account))
           {
            double amount;
            printf("Please insert amount \n");
            if(!CheckAmount(amount, scanf("%lf", &amount)));//this input is invalid
            else if(!CheckAccountWithdraw(account,amount));            
            else printf("your new balance is %.2f \n",Withdraw(account,amount));
           }
        }

        else if(input == 'C'){
           int account;
           printf("Please insert account number \n");
           scanf("%d", &account); 
           if(CheckAccount(account))
           {
             CloseAccount(account);
             printf("we close your account \n");  
           }

        }

        else if (input =='I')
        {
           double rate;
           printf("Please insert rate \n");
           if(!CheckAmount(rate, scanf("%lf", &rate)));
           else AddRate(rate);
        }
         else if (input =='P')
        {
          PrintAll();
        }
         else if (input =='E')
        {
          InitStart();
          on = false;
        }
        else {
            printf("No such transaction action exist, Please try again\n");
        }

    }
    return 0;
}

