#include <stdio.h>
#include <stdlib.h>
/**
Basic programes
**/


void printDifferentdatatypes() {
    int a = 9;
    int b = -9;
    int c = 89U;
    long int d = 99998L;

    printf("Integer value with positive data: %d\n", a);
    printf("Integer value with negative data: %d\n", b);
    printf("Integer value with an unsigned int data: %u\n",
           c);
    printf("Integer value with an long int data: %ld", d);
}
void printStarPattern() {
  int i, j, rows;
   printf("Enter the number of rows: ");
   scanf("%d", &rows);
   for (i = 1; i <= rows; ++i) {
      for (j = 1; j <= i; ++j) {
         printf("* ");
      }
      printf("\n");
   }
}
void threeCharacterReverse() {

    char operand1 = 'A';
    char operand2 = 'B';
    char operand3 = 'C';

    printf("The reverse of %c%c%c is %c%c%c\n",
        operand1, operand2, operand3,
        operand3, operand2, operand1);

}

void areaAndPerimeterOfRectangle()
{
        int l = 0, b = 0;
        printf("Enter length of the rectangle");
        scanf("%d", &l);
        printf("Enter bredth of the rectangle");
        scanf("%d", &b);
    printf("Area of rectangle is : %d", l * b);
    printf("\nPerimeter of rectangle is : %d", 2 * (l + b));
    return 0;
}

void diameterCircuferenceAndAreaOfCircle() {
    float radius, diameter, area, circumference;
    float PI = 3.14;

    printf("Enter radius of the circle: ");
    scanf("%f", &radius);

    diameter = 2 * radius;
    circumference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("Diameter of circle: %f\n", diameter);
    printf("Circumference of circle: %f\n", circumference);
    printf("Area of circle: %f", area);
}

void swapVariablesWithoutThird() {
 int a = 0, b = 0;

  printf("Enter operand 1");
        scanf("%d", &a);
        printf("Enter operand 2");
        scanf("%d", &b);

    printf("a = %d b = %d\n", a, b);

    a = a + b;
    b = a - b;
    a = a - b;

    printf("a = %d b = %d\n", a, b);
    return 0;
}

void cmToMeterAndKilometer() {
    float cm, meter, km;
    printf("Enter length in centimeter: ");
    scanf("%f", &cm);

    /* Convert centimeter into meter and kilometer */
    meter = cm / 100.0;
    km    = cm / 100000.0;

    printf("Length in Meter = %.2f m \n", meter);
    printf("Length in Kilometer = %.2f km", km);
}
