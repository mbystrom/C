#include <stdio.h>

int num1,num2,num3;

main ()
{
    printf ("Input 3 numbers, comma separated: ");
    scanf ("%d, %d, %d", &num1, &num2, &num3);
    
    int sum = num1 + num2 + num3;
 
    printf ("The sum of your numbers is %d", sum);

    return 0;
}
