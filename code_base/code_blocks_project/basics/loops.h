#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void naturalNumbers() {
    int start = 1, end;
    printf("Enter limit for natural numbers");
    scanf(" %d", &end);
    while(start<= end){
        printf(" %d", start);
        start++;

    }
     printf(" \n ");
}

void naturalNumbersInReverse() {
    int start;
    printf("Enter limit for natural numbers in reverse order");
    scanf(" %d", &start);
    while(start>=1){
        printf(" %d", start);
        start--;
    }
}

void printCharacter() {
    char alphabet='a';//char a =97;
    printf("\n English alphabets \n");
    while(alphabet != '{'){
        printf(" %c", alphabet);
        alphabet++;
    }
}
void evenNumbers(int limit) {
 int number = 0;
 printf("\nEven numbers upto %d\n",limit);
 while(number<=limit){
    if(number %2 == 0) {
        printf(" %d", number);
    }
    number++;
 }
}

void oddNumbers(int limit) {
 int number = 0;
 printf("\nOdd numbers upto %d\n",limit);
 while(number<=limit){
    if(number %2 == 1) {
        printf(" %d", number);
    }
    number++;
 }
}

void sumNumbers(int limit) {
 int number = 0;
 int sumValue = 0;
 printf("\nSum of numbers upto %d\n",limit);
 while(number<=limit){
  //printf("\nCurrent Sum %d + %d\n", number, sumValue);
   sumValue = sumValue + number;
    number++;
 }
 printf("Result : %d",sumValue);
}


void sumEvenNumbers(int limit) {
 int number_ = 0;
 int sumValue_ = 0;
 printf("\nSum of even numbers upto %d\n",limit);
 while(number_<=limit){
  if(number_%2 == 0){
   sumValue_ = sumValue_ + number_;
  }
    number_++;
 }
 printf("Result : %d", sumValue_);
}

void sumOddNumbers(int limit) {
 int number_ = 0;
 int sumValue_ = 0;
 printf("\nSum of odd numbers upto %d\n",limit);
 while(number_<= limit){
  if(number_%2 == 1){
   sumValue_ = sumValue_ + number_;
  }
    number_++;
 }
 printf("Result : %d", sumValue_);
}

void multiplicationTable() {
    int operand=0,limit=0, result = 0, op2=0;
    printf("Multiplication table \n Enter operand ");
    scanf("%d",&operand);
    printf("\n Enter the limit ");
    scanf("%d",&limit);
    while(op2 <= limit) {
        result = operand * op2;
        printf("\n %d * %d = %d",operand,op2,result);

        op2++;
    }
}
void factorial(){
    int operand=0, result=1, counter=1;
    printf("Factorial \n Enter operand ");
    scanf("%d",&operand);
    while(counter <= operand){
        printf(" \n%d  %d", result,counter);
        result *= counter;
        counter++;
    }
    printf("\nFactorial is %d",result);

}

void noOfDigit() {
    int operand=0, result=1, counter=1;//counter
    printf("No Of Digits \n Enter operand ");
    scanf("%d",&operand);
    while((operand/10) != 0){
            operand/=10;
        counter++;
    }{}
    printf("No of Digits %d",counter);

}
void firstAndLastDigit() {
    int operand=0, digit;
    printf("\nFirst and Last Digit\n Enter operand ");
    scanf("%d",&operand);
    printf("\nLast digit %d",(operand%10));
    while (operand > 0) {
		digit = operand % 10;
 		// Division of two ints in C truncates result
		operand /= 10;
	}
	printf("\nFirst Digit %i\n", digit);
}

void sumOfFirstAndLastDigit() {
    int operand=0, firstDigit, lastDigit;
    printf("\nSum of first and last Digit\n Enter operand ");
    scanf("%d",&operand);
    lastDigit =  operand%10;
    while (operand > 0) {
		firstDigit = operand % 10;
 		// Division of two ints in C truncates result
		operand /= 10;
	}
	printf("\nSum of First and Last Digit %d \n", (firstDigit+lastDigit));
}
void sumOfDigitofanumber() {
    int operand=0, rem, sum;
    printf("\nSum of first and last Digit\n Enter operand ");
    scanf("%d",&operand);

   while (operand != 0)
    {
        rem = operand % 10;
        sum = sum + rem;
        operand = operand / 10;
    }
	printf("\nSum of the number is %d \n", sum);
}

void productOfDigitofanumber() {
    int operand=0, rem, prod;
    printf("\nSum of first and last Digit\n Enter operand ");
    scanf("%d",&operand);

   while (operand != 0)
    {
        rem = operand % 10;
        prod = prod * rem;
        operand = operand / 10;
    }
	printf("\n Prduct of First and Last Digit %d \n", prod);
}

void reverseOfanumber() {
    int operand=0,reminder,reverse;
    printf("\nReverse of a number \n Enter operand ");
    scanf("%d",&operand);

   while (operand != 0) {
    reminder = operand % 10;
    reverse = (reverse * 10) + reminder;
    operand /= 10;
  }
	printf("\nReverse of the number %d \n", reverse);
}

void checkPalindrome() {
    int operand=0,reminder,reversed;
    printf("\nReverse of a number \n Enter operand ");
    scanf("%d",&operand);

    int orginalNumber = operand;

      while (operand != 0) {
        reminder = operand % 10;
        reversed = reversed * 10 + reminder;
        operand /= 10;
    }

    // palindrome if orignal and reversed are equal
    if (orginalNumber == reversed)
        printf("%d is a palindrome.", orginalNumber);
    else
        printf("%d is not a palindrome.", orginalNumber);

}
void frequencyOfDigit(){
    int operand, digit;
    int frequency[10] = {0};

    printf("\nFrequncy of Digit\n Enter a operand: ");
    scanf("%d", &operand);

    long num, n;
    int i, lastDigit;

    for(i=0; i<10; i++)
    {
        frequency[i] = 0;
    }
    n = operand;

    while(n != 0)
    {
        lastDigit = n % 10;
        n /= 10;
        frequency[lastDigit]++;
    }
    printf("Frequency of each digit in %lld is: \n", num);
    for(i=0; i<10; i++)
    {
        printf("Frequency of %d = %d\n", i, frequency[i]);
    }

    return 0;
}

void displayAsciiValues() {

  char operand;
    for(operand = 'a'; operand <= 'z'; operand++) {
        printf("ASCII value of %c = %d\n", operand, operand);
    }
    return 0;

}
/*
TODO: zero condition failing */
void displayNumberinWords(){

    int operand, num = 0;
    printf("Enter any number to print in words: ");
    scanf("%d", &operand);

    while(operand != 0)
    {
        num = (num * 10) + (operand % 10);
        operand /= 10;
    }

    while(num != 0)
    {
        switch(num % 10)
        {
            case 0:
                printf("Zero ");
                break;
            case 1:
                printf("One ");
                break;
            case 2:
                printf("Two ");
                break;
            case 3:
                printf("Three ");
                break;
            case 4:
                printf("Four ");
                break;
            case 5:
                printf("Five ");
                break;
            case 6:
                printf("Six ");
                break;
            case 7:
                printf("Seven ");
                break;
            case 8:
                printf("Eight ");
                break;
            case 9:
                printf("Nine ");
                break;
        }

        num = num / 10;
    }

}

void checkPrimeNumber()
{
  int n, i, flag = 0;
  printf("Enter a positive integer: ");
  scanf("%d", &n);

  if (n == 0 || n == 1)
    flag = 1;

  for (i = 2; i <= n / 2; ++i) {
    if (n % i == 0) {
      flag = 1;
      break;
    }
  }

  if (flag == 0)
    printf("%d is a prime number.", n);
  else
    printf("%d is not a prime number.", n);


}
void displayPrimeSeries()
{
  int operand=0,num,count;
  printf("\nPrime number Series \n Enter limit ");
  scanf("%d",&operand);

  for(num = 1;num<=operand;num++){
      count = 0;
      for(int i=2;i<=num/2;i++){
         if(num%i==0){
            count++;
         break;
      }
   }
   if(count==0 && num!= 1)
      printf("%d ",num);
   }

}

void sumofPrimeSeries()
{
  int operand=0,num,count,sum =0;
  printf("\nPrime number \n Enter limit ");
  scanf("%d",&operand);

  for(num = 1;num<=operand;num++){
      count = 0;
      for(int i=2;i<=num/2;i++){
         if(num%i==0){
            count++;
         break;
      }
   }
   if(count==0 && num!= 1)
      sum+=num;
   }
   printf("%d ",sum);

}

void checkAmstrong() {

  int num, originalNum, remainder, result = 0;
    printf("Enter a three-digit integer: ");
    scanf("%d", &num);
    originalNum = num;

    while (originalNum != 0) {
        remainder = originalNum % 10;
        result += remainder * remainder * remainder;
       originalNum /= 10;
    }

    if (result == num)
        printf("%d is an Armstrong number.", num);
    else
        printf("%d is not an Armstrong number.", num);
}




