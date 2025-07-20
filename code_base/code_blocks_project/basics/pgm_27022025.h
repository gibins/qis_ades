#include <stdio.h>
#include <stdlib.h>

void displayPatteren7()
{

    int operand,i,j,row,k;
    printf("\nEnter number of rows");
    scanf("%d",&operand);

    for(i = 0; i<operand; i++)
    {
        //space
        for(j = 0; j<(2*i)+1; j++)
        {
            printf(" ");

        }
            //star
        for(k = 0; k<2*(operand-i)-1; k++)
        {
            if(i==0||k==0||k==2*(operand-i)-2){
                printf("*");
            }else{
                printf(" ");
            }

        }


         printf("\n");
    }

}
