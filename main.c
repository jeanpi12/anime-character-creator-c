#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <string.h>
#include "decision.h"


// Convert MPH to KPH
/*
int main(void){

    int mph = 0;

    for (mph = 0; mph <= 250; mph += 25) {

        printf("MPH: %d\t", mph);
        printf("KPH: %.2f\n", (mph * 1.60934));
    }
    return EXIT_SUCCESS;
}

*/

//construct a table of Celsius to Fahrenheit conversions
/*
int main(void) {

    int fahr;


    for (fahr = 0; fahr <= 200; fahr +=20) {

        printf("Fahrenheit: %d\t Celsius: %.2f\n", fahr, (fahr - 32) * 5.0 / 9.0);
    }
    return EXIT_SUCCESS;
}

*/


// Demonstrate pointers
/*
int main(void) {

    char a = 'A';
    char *p = &a;

    printf("The value of a is: %c\n", a);
    printf("The value of p is: %p\n", (void *)p);
    printf("The value pointed to by p is: %c\n", *p);
    return EXIT_SUCCESS;

}

*/

// Demonstrate pointer arithmetic 


/*

int main(void) {

    char a[] = "Hello";
    char *p = a;

    printf("The value of a is: %s\n", a);
    printf("The value of p is: %p\n", (void *)p);
    printf("The value pointed to by p is: %c\n", *p);

    p++; // Move the pointer to the next character

    printf("After incrementing p:\n");
    printf("The value of p is: %p\n", (void *)p);
    printf("The value pointed to by p is: %c\n", *p);

    return EXIT_SUCCESS;
}

*/

// Demonstrate character arithmetic
/*
int main(void) {



    char a = 10;
    char b = 'B';

    printf("The value of a is: %d\n", a + b);

}

*/

// Demonstrate integer overflow
/*
long long int main(void) {

    long long int a = 9223372036854775807; // Maximum value for a signed 64-bit integer
    long long int b = 1;

    printf("The value of a is: %lld\n", a);
    printf("The value of b is: %lld\n", b);
    printf("The sum of a and b is: %lld\n", a + b); // This will cause an overflow

    return EXIT_SUCCESS;
}
    */

    // Demonstrate limits of data types
    /*
int main(void) {

    #define CHAR_MIN -128
    #define CHAR_MAX 127
    #define INT_MIN -2147483648
    #define INT_MAX 2147483647
    #define LONG_MIN -9223372036854775808
    #define LONG_MAX 9223372036854775807

    printf("CHAR_MIN = %d\n", CHAR_MIN);
    printf("CHAR_MAX = %d\n", CHAR_MAX);
    printf("INT_MIN = %d\n", INT_MIN);
    printf("INT_MAX = %d\n", INT_MAX);
    printf("LONG_MIN = %lld\n", LONG_MIN);
    printf("LONG_MAX = %lld\n", LONG_MAX);

    return EXIT_SUCCESS;
}

*/


// Demonstrate reading input from the user
/*
int main(void) {


    char name[200];

    printf("Enter the name of the user: ");
    fgets(name, sizeof(name), stdin); // Read a line of input from the user
    printf("Hello, %s!\n", name);

    return EXIT_SUCCESS;

}

*/
// Demonstrate floating-point precision
/*
int main(void) {

    float f = 3.14159365358979323846;
    float g = 0.0000265358f;

    printf("%.5f\n", f);
    printf("%.11f\n", g);

    f += g;

    printf("%.11f\n", f);
    
    return EXIT_SUCCESS;

}
*/

//LETS PRACTICE POINTERS AND ARRAYS






int main(void) {


    decision();




    return EXIT_SUCCESS;

}