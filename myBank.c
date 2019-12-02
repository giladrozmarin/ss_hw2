#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myBank.h"

double MainBank[2][50]; //2 line 50 row each line
int accountNumber = 901;
void InitStart()
{

    //init bank account if bank acoount=899 so it is a close account
    for (int i = 0; i < 50; ++i)
    {  
       MainBank[0][i] = 899;
       MainBank[1][i] = 0;
    }
}
void OpenBankAccount(double depositAmount)
{            
    //find the first available account
     for (int i = 0; i < 50; i++){
        if(MainBank[0][i] == 899){
          accountNumber =901+i;;
             break;
             } 
        } 
    if (accountNumber == 950)
    {
        MainBank[0][accountNumber - 901] = accountNumber; //open account
        MainBank[1][accountNumber - 901] = depositAmount; //deposit amount
        printf("your account number is %0.lf \n", MainBank[0][accountNumber - 901]);
        accountNumber =951;
        return;
    }
    
    if (accountNumber == 951)
    {        

        printf("you can't open account because our bank is in full \n");
        return;
    }

    else
    {
        MainBank[0][accountNumber - 901] = accountNumber; //open account
        MainBank[1][accountNumber - 901] = depositAmount; //deposit amount
        printf("your account number is %0.lf \n", MainBank[0][accountNumber - 901]);
        return;
    }
}
bool CheckAccount(int checkaccountnumber)
{
    if (checkaccountnumber<901 || checkaccountnumber >950)
    {
        printf("This bank account is not exsit \n");
        return false;
    }
    else if (MainBank[0][checkaccountnumber-901] == 899)
    {
        printf("This bank account is not exsit \n");
        return false;
    }
    
    else {return true;}
}
double BalanceCheckAccount(int accountnumber){
   return  MainBank[1][accountnumber-901];
}
bool CheckAmount(double amount, int scanfVal)
{
    if (amount < 0 || scanfVal != 1)
    {
        printf("The amount must be a number that bigger or equal to 0\n");
        return false;
    }
    else
        return true;
}
double Deposit(int account,double amount){
 
 return MainBank[1][account-901]+=amount;

}
bool CheckAccountWithdraw(int checkaccountnumber,double amount)
{

    if ((MainBank[0][checkaccountnumber - 901] - amount) <0){
        printf("Sorry about that but you don't have enough money in ypur account check you balance \n");
        return false;
    }
    else
        return true;
 
}
double Withdraw(int account,double amount){
 
 return MainBank[1][account-901]-=amount;

}
void CloseAccount(int account){

    MainBank[0][account-901]=899;
    MainBank[1][account-901] = 0;

        } 

void AddRate(double rate){

    for (int i = 0; i < 50; ++i)
    {  
       if(MainBank[0][i]!=899)
        MainBank[1][i] +=((rate * 100)/100);
    }
  

}
void PrintAll()
{
    for (int i = 0; i < 50; ++i)
    {  
       if(MainBank[0][i]!=899)
       {
        printf("Account number %0.lf \n",MainBank[0][i]);
        printf("Your balance is %2.lf \n",MainBank[1][i]);
        printf("\n");
       }
       
    }

}
