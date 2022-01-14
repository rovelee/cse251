#include<stdio.h>
#include<math.h>
/*
 In this function, L is in Henrys and C is in Farads. 
 The result is in radians per second. There are 2pi radians in a cycle, so
 the conversion from radians to Hertz is f = w / 2pi. 
 Write a program named rlc.c that inputs the capacitance in microfarads 
 (1/1,000,000th of a Farad) and the inductance in millihenrys (1/1000 of a Henry). 
 The program should output resonant frequency in Hertz.  
 The program must use the scanf() function to get the capacitance in microfarads 
 and the inductance in millihenrys from the user. 
*/
int main(){
    double r,l,c;
    printf("Input Capacitance (microfarads): ");
    scanf("%lf",&c);
    printf("\nInput Inductance (millihenrys): ");
    scanf("%lf",&l);
    c/=1000000;
    l/=1000;
    r=1/(pow(c*l,0.5) * 2 * M_PI);
    printf("\nResonant Frequency is %.3f",r);
    return 0;
}