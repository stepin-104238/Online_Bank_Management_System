#include<stdio.h>
#include<string.h>



struct bank
{
    char custname[100];
    int accno;
    int accbal;
    char add[100];
    char city[100];
};


int createaccount();
void viewaccount(int n);
void addmoney(int n);
void withdraw(int n);
void transfer(int n);
