#include <stdio.h>
#include <string.h>

/* 
 * Name : <Insert name>
 * Program to experiment with files
 */
 void Reverse(char str[]);

 int main(int argc, char *argv[])
 {
    if(argc < 3)
    {
        printf("Insufficient arguments\n");
        return 1;
    }
    
    printf("Copy from file: %s\n", argv[1]);
    printf("Copy to file: %s\n", argv[2]);
 
    FILE *inFile;
    FILE *outFile;

    inFile = fopen(argv[1], "r");
    if(inFile == NULL){
        printf("Unable to open file %s\n", argv[1]);
        return 1;
    }
    outFile = fopen(argv[2], "w");
    if(outFile == NULL){
        printf("Unable to open file %s\n", argv[2]);
        return 1;
    }

    char line[120];
    /* While we are not at the end of the file */
    while(!feof(inFile))
    {
        /* Read a line of text from the file */
        if(fgets(line, sizeof(line), inFile)!=NULL){
            /* Remove the newline at the end of the line */
            if(strlen(line) > 0)
                line[strlen(line) - 1] = '\0';

            Reverse(line);        
            // printf("%s\n", line);
            fprintf(outFile, "%s\n", line);
        };
    }
    fclose(inFile);
    fclose(outFile);
 }
  
void Reverse(char str[] )
{
    int front = 0;       
    int back = strlen(str) - 1;  
    char t;             /* A temporary place to put a character */
    
    while (front < back)
    {
        t = str[front];
        str[front] = str[back];
        str[back] = t;
        front++;
        back--;
    }
}