#include <stdio.h>

#define MaxWord 20

int main(){
    char c;
    char str[MaxWord+1];

    puts("Enter text. Include a dot(',') to end a sentence to exit:");
    do{
        c=getchar();
    }while(c!='.');
}