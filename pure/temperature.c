#include <stdio.h>

float tempC;
float tempF;
char input[50];

int
main ()
{
    printf ("Input a temperature (C): ");
    fgets (input, sizeof (input), stdin);
    sscanf (input, "%f", &tempC);
 
    tempF = ((9.0 / 5.0) * tempC) + 32.0;
 
    printf ("%f degrees Celsius is %f degrees Fahrenheit", tempC, tempF);

    return 0;
}
