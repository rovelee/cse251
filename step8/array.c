#include<stdio.h>

#define NumMovies 10
//这是一个数组的简单例子
int main(){
    // double gross[5] = {4633070, 3856195, 3171189, 1877685, 3251622};
    // double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622};
        double gross[NumMovies] = {4633070, 3856195, 3171189, 1877685, 3251622,
                               3156594, 1629735, 2659234, 2028036, 510768};
    double sum;
    char *names[NumMovies] = {"Hall Pass", "Unknown", "I Am Number Four", "The King's Speech", 
                         "Just Go With It", "Gnomeo and Juliet", "Drive Angry", 
                         "Justin Beiber: Never Say Never", "Big Mommas: Like Father, Like Son", 
                         "True Grit"};
    // sum = gross[0] + gross[1] + gross[2] + gross[3] + gross[4];
    
    sum = 0;
    int i;

    // for(i = 0; i<5; i++){
    //     sum += gross[i];
    // }
    // for(i=0;i<NumMovies;i++)
        // sum+=gross[i];
    for(i=0;i<NumMovies;i++)
        printf("Movie %2d %33s: %.0f\n", i+1, names[i], gross[i]);
    // printf("Total gross for these films was $%.0f\n", sum); 

    int highestGrossIndex = 0;
    double highestGross = 0;
    for(i = 0; i<NumMovies; i++){
        if(gross[i] > highestGross){
            highestGrossIndex = i;
            highestGross = gross[highestGrossIndex];
        }
    }
    printf("The highest grossing film is: %s\n", names[highestGrossIndex]);

    double maxGross[5] = {500000, 1000000, 2000000, 4000000, 10000000};
    int j,count,maxi;
    double max;
    for(j=0;j<5;j++){
        max = 0;
        count = 0;
        for(i = 0; i<NumMovies; i++){
            if(gross[i]<maxGross[j]&&gross[i]>max){
                maxi = i;
                max = gross[i];
                count++;
            }
        }
        if(count == 0)
            printf("No film less than %.0f\n", maxGross[j]);
        else
            printf("The highest gross less than %.0f is %33s at %.0f\n", maxGross[j], names[maxi], max);
    }
}