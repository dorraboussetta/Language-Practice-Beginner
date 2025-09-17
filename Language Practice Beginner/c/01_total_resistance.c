#include <stdio.h>
#include <stdlib.h>

/*
 * This program calculates the total resistance of three resistors
 * connected in series and in parallel. The user enters the values
 * of r1, r2, and r3, and the program prints the series and parallel
 * equivalent resistances.
 * What I learned: scanf and practicing the c language syntax more.
 */

int main()
{
   int r1, r2, r3;
   int r_series;
   float r_parallel;

   printf("Enter the value of r1: ");
   scanf("%d", &r1);

   printf("Enter the value of r2: ");
   scanf("%d", &r2);

   printf("Enter the value of r3: ");
   scanf("%d", &r3);

   // Series resistance
   r_series = r1 + r2 + r3;

   // Parallel resistance
   r_parallel = (float)(r1 * r2 * r3) / (r1*r2 + r1*r3 + r2*r3);

   printf("rseries is : %d \n", r_series);
   printf("rparallel is : %f\n", r_parallel);

   return 0;
}
