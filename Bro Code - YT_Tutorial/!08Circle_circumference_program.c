#include <stdio.h>

int main(){

    const double PI = 3.14159;
    double radius;
    double circunference;
    double area;

    printf("\nEnter the radius of the circle: ");
    scanf("%lf", &radius);

    circunference = 2 * PI * radius;
    area = PI * radius * radius;

    printf("\nCircunference: %lf", circunference);
    printf("\nArea: %lf", area);

    return 0;
}