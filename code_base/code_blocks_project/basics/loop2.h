
#include <stdio.h>
#include <stdlib.h>

/**
write a program to find perfect numbers between 1 to n
**/
void displayPerfectNumberSeries() {
    int operand,sum;
    printf("\nEnter the limit ");
    scanf("%d",&operand);
    for(int i=1; i<=operand; i++)
    {
        sum = 0;
        for(int j=1; j<i; j++)
        {
            if(i % j == 0)
            {
                sum += j;
            }
        }
        if(sum == i)
        {
            printf("%d ", i);
        }
    }


}


/**

write a program to check whether a number is strong or not

**/

void checkStrongNumber(){


     int operand, original, rem, sum=0, fact, i;
	  printf("\nEnter the limit ");
	 scanf("%d",&operand);

	 original = operand;

	 /* Finding sum */
	 while(operand != 0)
	 {
		  rem = operand%10;

		  /* Finding Factorial */
		  fact = 1;
		  for(i=1; i<=rem; i++)
		  {
		   	fact = fact*i;
		  }

		  sum = sum + fact;
		  operand = operand/10;
	 }

	 /* Making decision */
	 if(sum == original)
	 {
	  	printf("%d is STRONG.", original);
	 }
	 else
	 {
	  	printf("%d is NOT STRONG.", original);
	 }
}

/**
C program to print strong numbers between 1 to n
**/
void displayStrongNumberSeries() {
    int i, j, cur, lastDigit, operand;
    long fact, sum;

    printf("Enter the limit: ");
    scanf("%d", &operand);

    printf("All Strong numbers between 1 to %d are:\n", operand);
    for(i=1; i<=operand; i++)
    {
        cur = i;
        sum = 0;
        while(cur > 0)
        {
            fact = 1ll;
            lastDigit = cur % 10;

            for( j=1; j<=lastDigit; j++)
            {
                fact = fact * j;
            }

            sum += fact;

            cur /= 10;
        }
        if(sum == i)
        {
            printf("%d, ", i);
        }
    }
}

/**
  Write aprogram to print fibonacci series
**/

void displayFibonacciSeries() {
      int n, num1 = 0, num2 = 1, nextNum;

    printf("Enter the number of Fibonacci numbers to generate: ");
    scanf("%d", &n);

    printf("Fibonacci Series: ");

    for (int i = 1; i <= n; ++i) {
        printf("%d, ", num1);
        nextNum = num1 + num2;
        num1 = num2;
        num2 = nextNum;
    }
}




