#include <stdio.h>

int sum(int a[], int size, int s);

int main()
{
    int a[10] = { 1, 7, 5, 17, 4, -2, 5, 1, 6, 8 };
    printf("%d\n", sum(a, sizeof(a)/sizeof(a[0]), 0));

    return 0;
}

int sum(int a[], int size, int s)
{
    s += a[size];
    if (size == 0) return s;
    else return sum(a, size-1, s);
}
