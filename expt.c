#include <stdio.h>
#include <stdlib.h>
#include "mult.h"

//A recursive function that computes exponents.
int expt(int x, int y) {
    if (y == 1)
    {
        int answer = abs(x);
        return answer;
    }
    else
    {
        x = abs(x);
        y = abs(y);
        int answer = mult(x, expt(x, y-1));
        return answer;
    }
}

int test(void) {
    //Test multiplication:
    printf("2 * 2 = %i\n", mult(2, 2));
    printf("3 * 9 = %i\n", mult(3, 9));
    printf("-3 * 9 = %i\n", mult(-3, 9));
    printf("3 * -9 = %i\n", mult(3, -9));
    printf("-3 * -9 = %i\n", mult(-3, -9));

    //Test exponentiation:
    printf("2^8 = %i\n", expt(2, 8)); //should be 256
    printf("2^3 = %i\n", expt(2, 3)); //should be 8
    printf("(-2)^3 = %i\n", expt(-2, 3)); //should be -8
    return 0;
}   