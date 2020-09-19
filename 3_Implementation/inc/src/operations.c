#include "header.h"
int createaccount()
{
    static int i=0,n=0;
    printf("Enter customer name:\n");
    scanf("\n20%s",e[i].custname);
    printf("Enter the acc no:\n");
    scanf("%d",&e[i].accno);
    e[i].accbal=0;
    printf("Enter the customer address:\n");
    scanf("\n20%s",e[i].add);
    printf("Enter the bank branch:\n");
    scanf("\n20%s",e[i].city);
    printf("Account Created Successfully\n");
    n++;i++;
    return n;
}

void viewaccount(int n)
{
    if(n==0)
    {
        printf("No Account to display\n");
        goto end;
    }
    int i,acc, flag=0, z;
    printf("Enter your Account number\n");
    scanf("%d",&acc);
    for(i=0;i<n;i++)
    {
        if(acc==e[i].accno)
        {
            z=i;
            flag=1;
            break;
        }
    }
        if(flag==1)
        {
            printf("Welcome User\n");
            printf("Name : %20s\n",e[z].custname);
            printf("Account Number : %d\n",e[z].accno);
            printf("Available Balance : Rs. %d\n",e[z].accbal);
            printf("Address : 20%s\n",e[z].add);
            printf("Bank City : 20%s\n",e[z].city);
        }
        else
        {
            printf("Invalid Account\n");
        }
    end:
    ;
}

void addmoney(int n)
{
    if(n==0)
    {
        printf("No Account to display\n");
        goto end;
    }
    int z,i,acc,amount,flag=0;
    printf("Enter the Account number\n");
    scanf("%d",&acc);
    printf("Enter the amount need to be add in your account\n");
    scanf("%d",&amount);
    for(i=0;i<n;i++)
    {
        if(acc==e[i].accno)
        {
            e[i].accbal=e[i].accbal+amount;
            z=i;
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
    printf("Amount Credited Successfully!!!\n");
    printf("Your Available Balance is Rs.%d\n",e[z].accbal);
    }
    else
    {
        printf("Account not found\n");
    }
    end:
    ;
}

void withdraw(int n)
{
    if(n==0)
    {
        printf("No Account to display\n");
        goto end;
    }
    int z,i,acc,amount, flag=0;
    printf("Enter the Account number\n");
    scanf("%d",&acc);
    printf("Enter the amount need to be withdraw from your account\n");
    scanf("%d",&amount);
    for(i=0;i<n;i++)
    {
        if(acc==e[i].accno)
        {
            if(e[i].accbal > amount)
            {
                e[i].accbal=e[i].accbal-amount;
                z=i;
                flag=1;
                break;
            }
            else
            {
                printf("Insufficient amount\n");
                flag=2;
                break;
            }
        }
    }
    if(flag==1)
    {
        printf("Cash Withdraw has been  Successfully Done!!!\n");
        printf("Your Current Balance is Rs.%d\n",e[z].accbal);
    }
    else if(flag!=2)
    {
        printf("Invalid account\n");
    }
    end:
    ;
}

void transfer(int n)
{
    if(n==0)
    {
        printf("No Account to display\n");
        goto end;
    }
    int z,y,i,acc,receiver,amount,flag1=0, flag2=0;
    char a[100];
    printf("Enter your Account number\n");
    scanf("%d",&acc);
    printf("Enter the receiver account number\n");
    scanf("%d",&receiver);
    printf("Enter the amount need to be Transfer from your account\n");
    scanf("%d",&amount);
    for(i=0;i<n;i++)
    {
        if(acc==e[i].accno)
        {
            e[i].accbal=e[i].accbal-amount;
            z=i;
            flag1=1;
        }
        if(receiver==e[i].accno)
        {
            e[i].accbal=e[i].accbal+amount;
            strcpy(a,e[i].custname);
            flag2=1;
        }
    }
    if(flag1==1 && flag2==1)
    {
        if(e[z].accbal > amount)
        {
            printf("Transaction Successfull!!!\n");
            printf("The amount Rs.%d is transferred to %s's account\n",amount,a);
            printf("Your Available Balance is Rs.%d\n",e[z].accbal);
        }
        else
        {
            printf("Insufficient balance\n");
        }
    }
    else if(flag1==0 && flag2==1)
    {
        printf("Sender account is invalid\n");
    }
    else if(flag1==1 && flag2==0)
    {
        printf("Receiver account is invalid\n");
    }
    else
    {
        printf("Both accounts are invalid\n");
    }
    end:
    ;
}
