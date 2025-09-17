#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a,b, per;

    printf("Enter the length of the rectangle: \n");
    scanf("%d", &a);

    printf("Enter the width of the rectangle: \n");
    scanf("%d", &b);

    per = 2 * (a + b);

    printf("The perimeter is: %d\n ", per);


return 0;
}
