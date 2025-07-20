#include <stdio.h>
#include <stdlib.h>

findMaxandMin()
{
    int a[100], maxValue=0, minValue=0;
    printf("Enter 5 numbers");

    for(int i=0; i<5; i++)
    {
        scanf("%d", &a[i]);
    }
    // for(int k=0; k<5; k++)
    // {
    for(int j=0; j<5; j++)
    {
        if(maxValue<a[j])
        {
            maxValue= a[j];
        }
        if(minValue>a[j] || minValue == 0)
        {
            minValue= a[j];
        }
    }
    //}
    printf("\nMax : %d", maxValue);
    printf("\nMin : %d", minValue);
}

void numberOfOddEven()
{
    int a[100], evenCount=0, oddCount=0;
    printf("Enter 5 numbers");

    for(int i=0; i<5; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<5; i++)
    {

        if(a[i]%2 == 0)
        {

            evenCount++;
        }
        else
        {
            oddCount++;
        }


    }
    printf("\nEvenCount %d",evenCount);
    printf("\nOddCount %d", oddCount);

}
void copyArray()
{
    int sizeOfArray;

    printf("Enter size of the array");
    scanf("%d",&sizeOfArray);

    int a[sizeOfArray],b[sizeOfArray];

    for(int i=0; i<sizeOfArray; i++)
    {
        scanf("%d", &a[i]);
    }

    for(int i=0; i<sizeOfArray; i++)
    {
        b[i]=a[i];
    }
    printf("\n First Array\n");
    for(int i=0; i<sizeOfArray; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n Second Array\n");
    for(int i=0; i<sizeOfArray; i++)
    {
        printf("%d ", b[i]);
    }


}

void arrayOperations()
{
    int sizeOfArray;

    printf("Enter size of the array");
    scanf("%d",&sizeOfArray);

    int a[sizeOfArray],b[sizeOfArray];
 printf("\nEnter the array\n");
    for(int i=0; i<sizeOfArray; i++)
    {
        scanf("%d", &a[i]);
    }
//traversal reverse
    for(int j=sizeOfArray-1; j>=0; j--)
    {
        printf("%d ",a[j]);
    }
}
