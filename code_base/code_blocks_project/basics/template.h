#include <stdio.h>
#include <stdlib.h>

void problemSolution()
{
    int operand;

    int *ptr;

    printf("Problem/Question\n Enter operand \n");
    scanf("%d",&operand);
    ptr = (int *) malloc(operand * sizeof(int));
    printf("Enter %d operands\n",operand);
    for(int i=0; i<operand; i++)
    {
        scanf("%d",&ptr[i]);
    }
        for(int i=0; i<operand; i++)
    {
        printf("%d ",ptr[i]);
    }

    ptr = (int *) realloc(operand-2 ,
                           sizeof(int));
    //free(ptr);
    printf("\n");
      for(int i=0; i<operand; i++)
    {
        printf("%d ",ptr[i]);
    }



}
