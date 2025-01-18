#include <stdio.h>

int main(){

    int x;         //declaration
    x = 123;      //inicialization
    int y = 321; //declaration + inicialization
    
    int age = 20;             //integer
    float gpa = 2.05;        //floating point number
    char grade = 'A';       //single character
    char name[] = "Lucas"; //array of characters

    printf("%s",name);
    printf("%d\n",age);
    printf("Hello %s\n",name);
    printf("You are %d year old\n",age);
    printf("Your average grade is %c\n",grade);
    printf("Your gpa is %f\n",gpa);


    return 0;
}