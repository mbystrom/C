#include <stdio.h>

int FindMin(int a[], int size, int min);

int main()
{
    int a[10] = { 1, 7, 5, 17, 4, -2, 5, 1, 6, 8 };
    printf("%d", FindMin(a, sizeof(a)/sizeof(a[0]), a[0]));

    return 0;
}

int FindMin(int a[], int size, int min)
{
    if (a[size] < min) min = a[size];
    if (size > 0) return FindMin(a, size-1, min);
    else return min;
}
