#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void passwordGen(char arg[]);

int main(int argc, char *argv[])
{
    char YandN;
    int choice2;
    if(argc == 2)
    {
        printf("Do you want your password too be this long %s Y/N: ",argv[1]);
        scanf("%c",&YandN);
        if(YandN == 'Y')
            passwordGen(argv[1]);
        if(YandN == 'N')
        {
            printf("What would you like your password too be: ");
            scanf("%d",&choice2);
        }
    }
    else
    {
        printf("Usage: ./a.out \"Password length\"\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

void passwordGen(char arg[])
{
    int x = atoi(arg);
    char rc = ' ';
    char re = ' ';
    srand((unsigned int)(time(NULL)));
    printf("Password: ");
    x = x / 2;
    for(int i = 0; i < x; i++)
    {
        int rpass = rand() % 10;
        char rp = rpass + '0';
        int cpass = 26 * (rand() / (RAND_MAX + 1.0));
        cpass = cpass +97;
        rc = (char) cpass;
        re = (char) rp;
        printf("%c%c",rc,re);
    }
}
