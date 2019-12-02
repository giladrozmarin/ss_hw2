#include <stdbool.h>


void InitStart();
bool CheckAmount(double amount, int scanfVal);
void OpenBankAccount(double depositAmount);
bool CheckAccount(int checkaccountnumber);
double BalanceCheckAccount(int accountnumber);
double Deposit(int account,double amount);
double Withdraw(int account,double amount);
bool CheckAccountWithdraw(int checkaccountWithdraw,double amount);
void CloseAccount(int account);
void AddRate(double rate);
void  PrintAll();
