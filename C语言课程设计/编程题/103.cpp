#include<stdio.h>
#include<string.h>
#define MAX 85
int main()
{
	int i,j,flag,len1=0,cnt=0;
	char ch,temp,str1[MAX],str2[MAX];
	gets(str1);
	len1=strlen(str1);
	for(i=0;i<len1;i++) 
	{
		flag=0;    
		for(j=0;j<i;j++)
		{
			if (str1[i]==str1[j]) 
			{
				flag=1;
			}
		}
		if(flag==0)
		{
			str2[cnt]=str1[i]; 
			cnt++; 
		}
	}
	for (i=0;i<cnt-1;i++) 
	{
		for (j=0;j<cnt-i-1;j++)
		{
			if (str2[j]>str2[j+1])
			{
				temp=str2[j];
				str2[j]=str2[j+1];
				str2[j+1]=temp;
			}
		}
	}
 
	for (i=0;i<cnt;i++)
	{
		printf("%c", str2[i]);
	}
	printf("\n");
	return 0;
}

