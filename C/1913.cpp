    #include <stdio.h>
    #include <string.h>

    int trans(int a)
    {
    int result;
    char str[3]={0};
    char str1[4]={0};


    if(a<1000) {
    sprintf(str,"%d",a);
    result=((int)str[0]-48)*60+((int)str[1]-48)*10+((int)str[2]-48)*1;}//3840  712  420+10+2=432
    else if(a>=1000) 
    {sprintf(str1,"%d",a);
    result=(  ((int)str1[0]-48)*10+((int)str1[1]-48))*60+((int)str1[2]-48)*10+(int)str1[3]-48;}

    return result;
    }
    int main()
    {int tra_time=0;
    int start,arrive;
    scanf("%d %d",&start,&arrive);
    start=trans(start);
    arrive=trans(arrive);
    tra_time=arrive-start;
    int hour,mins;
    hour=tra_time/60;
    mins=tra_time-60*hour;
    printf("%d hrs %d mins",hour,mins);



    }