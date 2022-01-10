#include <stdio.h>
#include <math.h>
#include <stdio.h>
/*
∗ CSE 251 Project 1
∗ By: rovely
∗
∗ Complete the following table:
∗
∗ a b n estimate
∗ −1 1 1883 1.178979838
∗ 0 10 11 0.485413695
∗ −1000 1000 11 180.818255110
∗ 10 15 1515 0.016860599
∗ 0.1 0.2 138 0.096211811
*/

void getInputs(double* a, double* b);
void printfNums(double I, double E, int n);
double calculateDelta(double a, double b, int n);
double calculateIntegralByRactangle(double a, double d, int n);
double f(double x);

int main(){
    double a, b, delta;
    int n = 10;
    
    getInputs(&a, &b);
    delta = calculateDelta(a, b, n);
    printf("Integral evaluation\n");
    double r1 = calculateIntegralByRactangle(a, delta, n);
    // printf("%d: %.9lf\n", n, r1);
    double r2, d = 1;

    while(1){
        if(n>=100000||d<=1e-10)
            break;
        n++;
        delta = calculateDelta(a, b, n);
        r2 = calculateIntegralByRactangle(a, delta, n);
        d = r1 - r2;
        r1 = r2;
        // printf("%d: %.9lf %.9le\n", n, r1, d);
    }
    printf("The n is: %d\n", n);
    printf("The integral result is %.9lf\n", r1);
}

void getInputs(double* a, double* b){
    printf("Enter a value for a: ");
    scanf("%lf", a);
    printf("Enter a value for b: ");
    scanf("%lf", b);
}

double calculateDelta(double a, double b, int n){
    return (b-a) / n;
}

void printfNums(double I, double E, int n){
    printf("%d: %lf %lf\n", n, I, E);
}

double calculateIntegralByRactangle(double a, double d, int n){
    int i;
    double result = 0;
    for(i=1; i<=n; i++)
        result += f(a+(i-0.5)*d)*d;
    return result;
}

double f(double x){
    if(x == 0)
        return 1;
    return (sin(M_PI*x)/(M_PI*x));
}