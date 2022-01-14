#include<stdio.h>
#include<stdlib.h>
/*
    Compute the taxable income as the annual income minus the 
    deductions computed in (v) using the following table:
    Over	But Not Over	The Tax Is	Of The Amount Over
    $0        $16,750         $0 + 10%           $0
    $16,750   $68,000        $1,675 + 15%       $16,750  
    $68,000   $137,300       $9,362.50 + 25%    $68,000
    $137,300  And Over       $26,687.50 + 28%   $137,300

*/

int main(){
    double income;
    printf("Enter your annual income: ");
    scanf("%lf",&income);
    if(income<9350.0){
    //  If the annual income is less than $9350,
    //the amount of tax owed is zero.
        printf("0");
        exit(0);
    }
    int status;
    printf("What is your filing status?\n");
    printf("1) single\n");
    printf("2) married filing jointly\n");
    printf("3) married filing separately\n");
    printf("Please enter anumber: ");
    scanf("%d",&status);
    int dependents;
    double taxa;
    switch (status)
    {
    case 2:
        dependents = 2;
        int kids;
        printf("How many children do you have? ");
        scanf("%d",&kids);
        dependents += kids;
        taxa = income-(11400 + dependents * 3650);
        break;
    default:
        dependents = 1;
        taxa = income-(5700+dependents * 3650);
        break;
    }
    double tax;
    if(taxa<16750) tax = taxa*0.1;
    else if(taxa<68000) tax = 1675 + (taxa-16750) * 0.15;
    else if(taxa<137300) tax = 9362.5 + (taxa-68000) * 0.25;
    else tax = 26687.5 + (taxa-137300) * 0.28;
    printf("%.2f\n",tax);
}