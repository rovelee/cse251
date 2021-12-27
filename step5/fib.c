#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/** Program to compute Fibonacci nubers */
int main(){
    
    int fn1 = 1; // F(n-1) druing the loop
    int fn2 = 0; // F(n-2) during the loop
    int f;// Computed Fibonacci number
    int i;// Loop counter
    
    /* Print the first two Fibonacci numbers */
    printf("0\n");
    printf("1\n");

    for(i = 0; i < 10; i++){
        f = fn1 + fn2; // Compute the number
        printf("F(%d) = %d\n",i , f);

        /* Update F(n-1) and F(n-2) */
        fn2 = fn1;
        fn1 = f;
    }
}