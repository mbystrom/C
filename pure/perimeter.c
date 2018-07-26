#include <stdio.h>

char input[50];
float width;
float height;

int main()
{
    printf("width of the rectangle? ");
    scanf("%f", &width);
    
    printf("height of the rectangle? ");
    scanf("%f", &height);
    
    float perim = 2 * (width + height);
    printf("the perimeter of your rectangle is %f", perim);

    return 0;
}
