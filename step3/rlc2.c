#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>
/*
    copy file
*/
void compare(int a){
    if(a<0){
        printf("You moron, you entered a negative inductance!\n");
        exit(1);//exit with an error indicated
    }else if(a==0){
        printf("You are really dumb, you entered zero.\n");
        exit(1);
    }
}
int main(){
    double r,l,c;
    printf("Input Capacitance (microfarads): ");
    scanf("%lf",&c);
    compare(c);
    // if(c<0){
    //     printf("You moron, you entered a negative inductance!\n");
    //     exit(1);
    // }
    printf("\nInput Inductance (millihenrys): ");
    scanf("%lf",&l);
    compare(l);
    // if(l<0){
    //     printf("You moron, you entered a negative inductance!\n");
    //     exit(1);
    // }
    c/=1000000;
    l/=1000;
    r=1/(pow(c*l,0.5) * 2 * M_PI);
    printf("\nResonant Frequency is %.3f",r);
    return 0;
}