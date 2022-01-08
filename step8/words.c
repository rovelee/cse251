#include <stdio.h>

#define MaxWord 20

int main(){
    char c;
    char str[MaxWord+1];
    char lonstr[MaxWord];
    int len = 0;
    int len2=0;
    int sum = 0;
    int llen = 0;
    puts("Enter text. Include a dot(',') to end a sentence to exit:");
    do{
        c=getchar();
        if(c != ' ' && c != '.'){
            str[len] = c;
            len++;
        }
        else{
            len2++;
          str[len]=0;
        //   printf("%s\n", str);
          if(len>llen){
              llen=len;
              int i=0;
              for(;i<len;i++)
                lonstr[i]=str[i];
          }
          sum+=len;
          len=0;  
        }
    }while(c!='.');
    int avg = sum/len2;
    //printf("%s\n", str);
    printf("average :%d\n",avg);
    printf("longest word:%s",lonstr);
}