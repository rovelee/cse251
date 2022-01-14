#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "transistors.h"

int main()
{
    // struct Transistor t1;
    // Tran t1;

    // t1 = InputTransistor();

    // DisplayTransistor(t1);

    // int i;
    // Tran trans[3];
    
    // printf("transistors!\n");
    
    // for(i=0;  i<3;  i++)
    // {
    //     trans[i] = InputTransistor();
    // }
    
    // printf("\nThe transistors:\n");
    // DisplayTransistor(trans[0]);

    int i;
    Tran *trans;
    int numTrans = 0;
    
    printf("transistors!\n");

    /* Allocate space for one transistor */
    trans = malloc(sizeof(Tran));
    numTrans = 1;
    
    /* Input the transistor */
    trans[0] = InputTransistor();

    char c;
    while(true){
        printf("Would you like to enter another transistor (Y/N)?");
        c = getchar();
        printf("%c", c);
        if(c!='Y'&&c!='y')
            break;
        // scanf("%c", &c);
        trans = realloc(trans, sizeof(Tran) * (++numTrans));
        
        trans[numTrans - 1] = InputTransistor();
    }
    
    /* Output the transistors */
    printf("\nThe transistors:\n");
    for(i=0;  i<numTrans;  i++)
    {
        DisplayTransistor(trans[i]);
        printf("\n");
    }

    /* Free the memory */
    free(trans);
}
