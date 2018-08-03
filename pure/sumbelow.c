#include <stdio.h>

int SumBelow(int n);

int main()
{
    for (int i = -5; i <= 5; i++) {
        printf("sum below %d is %d \n", i, SumBelow(i));
    }

    return 0;
}

int SumBelow(n)
{
    if (n == 0) return 0;
    else if (n < 0) return n + SumBelow(n+1);
    else return n + SumBelow(n-1);
}
