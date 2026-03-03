#include <stdio.h>
    #define LEAP_YEAR(y)          \
do {                                \
    if(((y)%4==0 && (y)%100!=0) || (y)%400==0) \
        printf("%s","L");    \
    else                            \
        printf("%s", "N");  \
} while(0)

int main()

{
    int y;
    scanf("%d",&y);
    LEAP_YEAR(y);
}