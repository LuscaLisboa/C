#include <stdio.h>
#include <stdbool.h>

int main(){

    char a = 'C';      // %c single character
    char b[] = "Bro"; // %s array of characters

    float c = 3.141592;            // %f 4 bytes (32 bits of precision) 6 - 7 digits
    double d = 3.141592653589793; // %lf 8 bytes (64 bits of precision) 15 - 16 digits

    bool e = true; // %d 1 byte (true or false)

    char f = 127;           // %d or %c 1 byte (-128 to +127)
    unsigned char g = 255; // %d or %c 1 byte (0 to +255)

    short int h = 32767;           // %d 2 bytes (-32,768 to +32,767)
    unsigned short int i = 65535; // %d 2 bytes (0 to +65,535)

    int j = 2147483647;           // %d 4 bytes (-2,147,483,648 to + 2,147,483,647)
    unsigned int k = 4294967295; // %u 4 bytes (0 to +4,294,967,295)

    long long int l = 9223372036854775807;            // %lld 8 bytes (-9,223,372,036,854,775,808 to +9,223,372,036,854,775,807)
    unsigned long long int m = 18446744073709551615U; // %llu 8 bytes (0 to 18,446,744,073,709,551,615)

    return 0;
}