#include<stdio.h>

#define MAXSIZE_OF_WORDS 21
#define MAXSIZE_OF_SENTENCE 21

int main(){
    /*
    Some final tasks to do and this program will be done:

    1. Have your program ignore words that are zero length. This happens if you type two spaces in a row. That will take just one simple test.

    2. Have your program print the average word length.

    3. Have your program print the longest word entered.
    */
   
    char c;
    char longest[MAXSIZE_OF_WORDS];
    char* words[MAXSIZE_OF_SENTENCE];
    int avg, counts, llongest;
    avg = 0;
    counts = 0;
    llongest = 0;

    do{
        char word[MAXSIZE_OF_WORDS];
        int len = 0;
        do{
            c = getchar();
            
        }while(c!=' ' && c!='\n' && c!='.');

        if(c != ' '&& c!='.'){
            word[len] = c;
            len++;
        }else{
            // printf("%s", word);
            if(len > llongest){
                llongest = len;
                int i;
                for(i=0;i<len;i++)
                    longest[i] = word[i];
            }
            avg += len + 1;
            len = 0;

            word[len] = c;
            words[counts] = word;
            counts++;
        }
    }while(c!='.');
    avg /= counts;
    int j;
    for(j = 0;j < counts;j++){
        printf("%s",words[j]);
    }
    printf("\naverage word length is: %d\n",avg);
    printf("the longest word is:%s\n",longest);
}