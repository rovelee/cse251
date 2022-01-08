#include <stdio.h>

#define MaxWord 20

int main(){
    char c;
    char str[MaxWord+1];
    int len = 0;
    puts("Enter text. Include a dot(',') to end a sentence to exit:");
    do{
        c=getchar();
        if(c != ' ' && c != '.'){
            str[len] = c;
            len++;
        }
        else{
          str[len]=0;
          printf("%s\n", str);
          len=0;  
        }
    }while(c!='.');

    //printf("%s\n", str);
}