#include <stdio.h>

int hours;
int minutes;

int main()
{
    printf("enter hours: ");
    scanf("%d", &hours);
    
    printf("enter minutes: ");
    scanf("%d", &minutes);
    
    int allMinutes = (hours * 60) + minutes;
    printf("that's %d minutes", allMinutes);
    
    return 0;
}
