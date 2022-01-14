#include<stdio.h>
int main(){
    printf("Playing Computer\n");
     int i = 1;
    int sum = 0;
    
    while(i < 5)
    {
        sum += i; //sum = 1 + 2 + 3 + 4 
        i++;
    }

    double q = 1;
    for(i = 1; i<=5; i++)
        q += i * i / 2.0; //q = 1 + 1/2 +4/2 + 9/2 + 16/2 + 25/2

    int j;
    for(i = 0; i<11; i++){
        if(i < 5)
            for(j = 0; j<=i; j++)
                printf("+");
        else 
            for(j=0; j<=(10-i); j++)
                printf("+");
        printf("\n");
    }
    printf("---\n");
    
    printf("sum=%d\n", sum);
    printf("q=%f\n", q);

}