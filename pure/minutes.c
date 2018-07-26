#include <stdio.h>

int minutes;

int main()
{
    printf("enter the number of minutes: ");
    scanf("%d", &minutes);
    
    int hours = floor(minutes / 60);
    int newMinutes = minutes - (hours * 60);
    
    printf("%d hours, %d minutes", hours, newMinutes);
    
    return 0;
}
