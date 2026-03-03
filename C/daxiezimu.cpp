#include <stdio.h>
int main()
{
    char str;
    while(scanf(" %c",&str)!=EOF)
    {
        if(str>='A'&&str<='Z')
            printf("Yes\n");
        else printf("No\n");

    }
    return 0;

}