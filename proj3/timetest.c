#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm tm = *localtime(&(time_t){time(NULL)});
    printf("Today is           %s", asctime(&tm));
    printf("%d %d %d %s\n",tm.tm_year,tm.tm_mon,tm.tm_yday,tm.tm_zone);
    tm.tm_mon -= 100;  // tm_mon is now outside its normal range
    time_t t = mktime(&tm); // recalculate tm
    printf("100 months ago was %s", asctime(&tm));
}
