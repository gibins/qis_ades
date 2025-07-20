#include <stdio.h>
#include <stdlib.h>

void displayPatteren()
{

    int operand,i,j,row;
    printf("\nEnter number of rows");
    scanf("%d",&operand);

    for(row = 1; row<=operand; row++)
    {
        //space
        for(i = 1; i<=(operand-row); i++)
        {
            printf(" ");

        }
            //star
        for(j = 1; j<=row; j++)
        {
                printf("*");

        }


         printf("\n");
    }

}
