#include <stdio.h>
int main()
{
int restspace=0;
int n=0;
int box[6];
for(int i=0;i<6;i++)
{
int a;
scanf("%d",&a);//box[]={1,2,3,4,5,6}
box[i]=a;
}
//6*6和5*5
int rest1=0;
n=box[5]+box[4];
rest1=(36-25)*box[4];//5*5的盒子剩余的量
box[5]=0;
box[4]=0;
//4*4
n=n+box[3];//box[3]个4*4
int rest=20*box[3];
int temp_box1=box[1];
box[1]=box[1]-5*box[3];//2*2
if (box[1]<=0) 
{box[1]=0; rest=0;}
else if(box[1]>0)   rest=rest-(temp_box1-box[1])*4;

//3*3
int addbox3full=0;
int restbox3=0;

if(box[2]%4==0) n=n+box[2]/4;
else if(box[2]%4!=0)
{
    addbox3full=box[2]/4;
    n=n+addbox3full+1;
    restbox3=box[2]%4;
    restspace=36-restbox3*9;
    int two_left=0;
    //2*2
    if(restbox3==1)
    {
    two_left=5;
    }
    if (restbox3==2)
    {
        two_left=3;
    }
    if (restbox3==3)
    {
        two_left=1;
    }
    restspace=restspace-two_left*4;


    if(box[1]<=two_left)
    {
        box[1]=0;
    }
    else{box[1]=box[1]-two_left;}


}
//2*2
if(box[1]!=0)
{
n=n+box[1]/9;
box[1]=box[1]%9;

restspace+=36-box[1]*4;
}
restspace+=rest1+rest;
//1*1
if(box[0]!=0)
{
    box[0]=box[0]-restspace;
    if(box[0]<=0) box[0]=0;
    else
    {
        n=n+box[0]/36;
        if(box[0]%36!=0) n=n+1;
    }
}
printf("%d",n);



}