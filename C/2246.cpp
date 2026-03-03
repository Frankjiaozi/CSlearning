#include <stdio.h>
#include <string.h>
int add(int arr1[],int arr2[],int len1,int len2,char result[])
{
	 int  max_length=(len1>len2)?len1:len2; 
	int start_length=max_length;//初始长度
	int carry=0;//进位符

	//逐位相加
	for(int i=0;i<max_length;i++)
	{	
		int num_a=(i<len1)?arr1[i]:0;
		int num_b=(i<len2)?arr2[i]:0;
		int sum=num_a+num_b+carry;
		result[i]=sum%10;
		carry=sum/10;
	}
	if(carry==1)
	{
		result[start_length]=1;
		start_length+=1;
	} 
return start_length;
	
}

//定义result
char result[10001];
int main()
{	int m;
	char s1[10000];
	char s2[10000];
	
	
	scanf("%d",&m);
	for(int i=0;i<m;i++)
		{
		scanf("%s %s",s1,s2);
		int arr1[(int)strlen(s1)];
		int arr2[(int)strlen(s2)];
		//对arr1进行倒序输入 
        int j=0;
		for(int p=(int)strlen(s1)-1;p>=0;p--)//67890->09876
										   //12345->54321
		{	
			arr1[j++]=s1[p]-'0'; 
		}
		//对arr2进行倒序输入  
        int t=0;
		 for(int i=(int)strlen(s2)-1;i>=0;i--)
		{	
			arr2[t++]=s2[i]-'0'; 
		}
int len1=sizeof(arr1)/sizeof(int);
int len2=sizeof(arr2)/sizeof(int);
int start_length=add(arr1,arr2,len1,len2,result);
for(int i=start_length-1;i>=0;i--)	
{
	printf("%d",result[i]);
}
printf("\n");
	}
	
}
//1234567890987654321
//9876543210123456789
//11111111101111111110
