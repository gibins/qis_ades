#include <stdio.h>
#include <stdlib.h>
/*
C program to find ones complement of a binary number
*/
void getOnceComplementOfBinary()
{
    char binary[9], onesComp[9];
    int i, error=0;
    printf("Enter  binary value: ");
    scanf("%s",binary);
    for(i=0; i<9; i++)
    {
        printf("\nprocessing %c",binary[i]);
        if(binary[i] == '1')
        {
            printf("\n Inverted to 0 ");
            onesComp[i] = '0';
        }
        else if(binary[i] == '0')
        {
            printf("\n Inverted to 1 ");
            onesComp[i] = '1';
        }
    }

    printf("\nOriginal binary = %s", binary);
    printf("\nOnes complement = %s", onesComp);

}
/*
Write a program to find twos complement of a number
*/
void getTwosComplementOfBinary()
{
    char binary[9], onesComp[9], twosComp[9];
    int i, carry=1;

    printf("Enter bit binary value: ");
    scanf("%s",binary);

    for(i=0; i<8; i++)
    {
        if(binary[i] == '1')
        {
            onesComp[i] = '0';
        }
        else if(binary[i] == '0')
        {
            onesComp[i] = '1';
        }
    }

    for(i=7; i>=0; i--)
    {
        if(onesComp[i] == '1' && carry == 1)
        {
            twosComp[i] = '0';
        }
        else if(onesComp[i] == '0' && carry == 1)
        {
            twosComp[i] = '1';
            carry = 0;
        }
        else
        {
            twosComp[i] = onesComp[i];
        }
    }
    printf("Original binary = %s\n", binary);
    printf("Ones complement = %s\n", onesComp);
    printf("Twos complement = %s\n", twosComp);

}
/*
write a program to find binary to octal number system in c
*/
void convertBinaryToOctal()
{
    long int binarynum, octalnum = 0, j = 1, remainder;
    printf("Enter the value for  binary number: ");
    scanf("%ld", &binarynum);
    while (binarynum != 0)
    {
        remainder = binarynum % 10;
        octalnum = octalnum + remainder * j;
        j = j * 2;
        binarynum = binarynum / 10;
    }
    printf("Equivalent octal value: %lo", octalnum);
}


/*
write a c program to find binary number of a decimal number
*/
void convertBinaryToDecimal()
{
    int decimal_num, binary_num = 0, i = 1, remainder;
    printf("Enter a decimal number: ");
    scanf("%d", &decimal_num);
    while (decimal_num != 0)
    {
        remainder = decimal_num % 2;
        decimal_num /= 2;
        binary_num += remainder * i;
        i *= 10;
    }
    printf("Binary number: %d\n", binary_num);
}
void convertBinaryToHex()
{
    long int binaryval, hexadecimalval = 0, i = 1, remainder;

    printf("Enter the binary number: ");
    scanf("%ld", &binaryval);
    while (binaryval != 0)
    {
        remainder = binaryval % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryval = binaryval / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);

}

int convertOctalToBinary()
{
    int i = 0, decimal = 0, octal;
    while (octal!=0)
    {
        int digit = octal % 10;
        decimal += digit * pow(8, i);

        octal /= 10;
        i++;
    }

    printf("Decimal Value: %d\n",decimal);

    long long binary = 0;
    int rem;
    i = 1;

    while(decimal!=0)
    {
        rem = decimal % 2;
        decimal /= 2;
        binary += rem * i;
        i *= 10;
    }

    printf("Binary Value: %d",binary);
    return binary;

}

void convertOctalToDecmal()
{
    int operand;
    printf("Enter an Octal number: \n");
    scanf("%o", &operand);
    printf("\nDecimal is: %d", operand);

}

void convertOctalToHex()
{
    long int binaryval, hexadecimalval = 0, i = 1, remainder;
    int binaryValue = convertOctalToBinary();
     while (binaryValue != 0)
    {
        remainder = binaryValue % 10;
        hexadecimalval = hexadecimalval + remainder * i;
        i = i * 2;
        binaryValue = binaryValue / 10;
    }
    printf("Equivalent hexadecimal value: %lX", hexadecimalval);

}

void convertDecimalToBinary()
{
    int remainder,result = 0,multiplier = 1;
    int input;
    printf("Enter a Decimal Number\n");
    scanf("%d",&input);
    while(input){
        remainder = input%2;
        result = remainder*multiplier + result;
        multiplier*=10;
        input/=2;
    }
    printf("The binary version of the decimal value is: %d",result);

}

void convertDecimalToOctal()
{
    long decimalnum, remainder, quotient,octalnum=0;
    int octalNumber[100], i = 1, j;

    printf("Enter the decimal number: ");
    scanf("%ld", &decimalnum);
    quotient = decimalnum;

    while (quotient != 0)
    {
        octalNumber[i++] = quotient % 8;
        quotient = quotient / 8;
    }

    for (j = i - 1; j > 0; j--)
        octalnum = octalnum*10 + octalNumber[j];
    printf("Equivalent octal value of decimal no %d is: %d  ", decimalnum,octalnum);
}

void convertDecimalToHexaDecimal()
{
    int decimalNumber = 45;
    printf("Enter the decimal number: ");
    scanf("%d", &decimalNumber);
    printf("Hexadecimal number is: %X", decimalNumber);
}

void convertHexadecimalToBinary()
{
    char hex[100];
    printf("Enter hexadecimal");
    scanf("%s",hex);
   int i=0;
   while(hex[i])
   {
       switch(hex[i])
       {
           case '0':
           printf("0000");
           break;
           case '1':
           printf("0001");
           break;
           case '2':
           printf("0010");
           break;
           case '3':
           printf("0011");
           break;
           case '4':
           printf("0100");
           break;
           case '5':
           printf("0101");
           break;
           case '6':
           printf("0110");
           break;
           case '7':
           printf("0111");
           break;
           case '8':
           printf("1000");
           break;
           case '9':
           printf("1000");
           break;
           case 'A':
           printf("1010");
           break;
           case 'a':
           printf("1010");
           break;
           case 'B':
           printf("1011");
           break;
           case 'b':
           printf("1011");
           break;
           case 'C':
           printf("1100");
           break;
           case 'c':
           printf("1100");
           break;
           case 'D':
           printf("1101");
           break;
           case 'd':
           printf("1101");
           break;
           case 'E':
           printf("1110");
           break;
           case 'e':
           printf("1110");
           break;
           case 'F':
           printf("1111");
           break;
           case 'f':
           printf("1111");
           break;
       }
       i++;
   }
}

void convertHexadecimalToOctel()
{

}
/**
**/

void convertHexadecimalToDecimal()
{
    int n;
    printf("Enter hexaDecimal number");
    scanf("%x", &n);
    printf("%d", n);
    return 0;
}
