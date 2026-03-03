#include <stdio.h>
#include <string.h>

void reverse(char *str) {
    int len = strlen(str);
    char temp;
    for (int i = 0; i < len / 2; i++) {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}



int main()
{
    char s1[100],s2[100];
    scanf("%s",s1);
    scanf("%s",s2);
    reverse(s1);
    s1[(int)strlen(s1)]='\0';
    reverse(s2);
    s2[(int)strlen(s2)]='\0';
    strcat(s1,s2);
    printf("%s",s1);

    
}