#include <stdio.h>
int main()
{
    float basic=0.0,obt=0.0,house=0.0;
    while(scanf("%f",&basic)!=EOF)
    {
        obt=basic*0.4;
        house=basic*0.2;
        printf("物价津贴为%.6f\n",obt);
        printf("房屋津贴为%.6f\n",house);
        printf("总工资为%.6f\n",basic*1.6);
    }
    return 0;
}