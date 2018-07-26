#include <stdio.h>

int factorial(int n);

int main ()
{
    int num;
    printf("enter a number to factorialize: ");
    scanf("%d", &num);

    printf("the factorial of %d! is %d", num, factorial(num));

    return 0;
}

int factorial (int n)
{
    if (n == 0) return 1;
    else return (n * factorial(n-1));
}
