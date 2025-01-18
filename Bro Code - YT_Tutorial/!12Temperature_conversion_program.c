#include <stdio.h>
#include <ctype.h>

int main(){

    char unit;
    float temp;

    printf("\nIs the temperature in (F) or (C)?: ");
    scanf("%c", &unit);

    unit = toupper(unit);

    if(unit == 'C'){
        printf("\nEnter the temperature in Celcius: ");
        scanf("%f", &temp);
        temp = (temp * 9/5 + 32);
        printf("The temperature is %.1f Fahreinheit.", temp);
    }
    else if(unit == 'F'){
        printf("\nEnter the temperature in Fahreinheit: ");
        scanf("%lf", &temp);
        temp = ((temp - 32) * 5) / 9;
        printf("The temperature is %.1f Celsius.", temp);
    }
    else {
        printf("Please enter a valid unit. (F) for Fahreinreit, or (C) for Celsius.");
    }
    return 0;
}