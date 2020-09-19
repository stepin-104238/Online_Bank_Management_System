#include "header.h"
int main()
{
    //struct bank e[100];
    int n=0;
    int ch;
    for(;;)
    {
        printf("***************HDFC BANK**************\n");
        printf("1)Create Account\n2)View Account\n3)Add money\n4)withdraw money\n5)Transfer money\n6)exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        if(ch==6)
        {
            printf("Logout Successfull\n");
            break;
        }
        switch(ch)
        {
            case 1:
                n=createaccount();
                break;
            case 2: 
                viewaccount(n);
                break;
            case 3:
                
                addmoney(n);
                break;
            case 4:
                
                withdraw(n);
                break;
            case 5:
                
                transfer(n);
                break;
                
        }
    }
    return 0;
    
}
