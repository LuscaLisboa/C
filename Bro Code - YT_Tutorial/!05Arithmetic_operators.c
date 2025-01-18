#include <stdio.h>

int main (){

    /*
    + addition
    - subtration
    * multiplication
    / division
    % modulus
    ++ increment
    -- decrement
    */

    int x = 5;
    int y = 2;

    float z = x / (float)y;

    printf("%f\n",z);

    int a = x % y;

    printf("%d\n",a);

    x++;
    y--;

    printf("%d\n",x);
    printf("%d",y);

    x = x + 2;
    x+=2;

    x = x - 3;
    x-=3;

    x = x * 4;
    x*=4;

    x = x / 5;
    x/=5;

    x = x % 2;
    x%=2;

    return 0;
}