#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* 
 * Name : <lyh>
 * Program to determine combinations
 */

int Factorial(int n);

int Binominal(int n, int k);

int main()
{
    int n;
    int k;
    int b;
    
    printf("Input n: ");
    scanf("%d", &n);
    if(n < 1)
    {
        printf("Must be greater than zero\n");
        exit(1);
    }
    
    printf("Input k: ");
    scanf("%d", &k);
    if(k < 0 || k > n)
    {
        printf("Must be between 0 and %d inclusive\n", n);
        exit(1);
    }
    b = Binominal(n, k);
    // b = Factorial(n) / (Factorial(k) * Factorial(n-k));
    printf("%d items taken %d ways is %d\n", n, k, b);
}

int Factorial(int n){
    int f = 1;
    int i;
    for(i = 1; i<=n; i++){
        f *=i;
    }
    return f;
}

int Binominal(int n, int k){
    // return Factorial(n) / (Factorial(k) * Factorial(n-k));
    printf("n=%d k=%d\n", n, k);
    if(n == k) return 1;
    if(k == 0) return 1;
    return Binominal(n - 1, k - 1) + Binominal(n - 1, k);
}