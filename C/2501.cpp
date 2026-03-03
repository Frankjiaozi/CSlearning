#include <stdio.h>
#include <string.h>
//µ¹ÐòÊä³ö×Ö·û´®
void reverse(char result[],char str[])
{	int k=0;
	for(int i=(int)strlen(str)-1;i>=0;i--)
	{
		result[k]=str[i];
		k++;
	}
 } 
//½«Êý×Ö¸ÄÎª×Ö·û´®    987
void trans(int x,char result[])
{	char temp[100];
	int k=0;
	int add;
	while(x>0)
	{
	add=x%10;
	temp[k]=add+'0';
	k++;
	x=x/10;
	}
	temp[k]='\0';	
	reverse(result,temp);
	result[k]='\0';
}

void sum(char str[],char next[])
{	int sum_result=0;
	int len=(int)strlen(str);
	for(int i=0;i<len;i++)
	{
		sum_result+=str[i]-'0'; 
	}

	trans(sum_result,next);
}



int main()
{	char str[100];
char temp[100];

while(scanf("%s",str)!=EOF && str[0]!='0')
	{		sum(str,temp);
			strcpy(str,temp);
		while((int)strlen(temp)>1)
		{
			sum(str,temp);
			strcpy(str,temp);
			
			
		}
		printf("%s\n",temp);
	}
}  






