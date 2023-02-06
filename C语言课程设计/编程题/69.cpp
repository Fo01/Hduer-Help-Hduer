#include<stdio.h>
#include<math.h>
#define sc(a) scanf("%ld",&a);

int main()
{
    char ch;
	int b,sum=0,flag=0;
	scanf("%d",&sum);
    while(scanf("%c",&ch))
	{
        scanf("%d",&b);
        if(ch=='-')
            sum-=b;
        else if(ch=='+')
            sum+=b;
        else if(ch=='*')
            sum*=b;
        else if(ch=='/')
		{
            if (b==0)
			{
                flag=1;
                break;
            }
            else sum/=b;
        }
        else if(ch=='=') break;
        else
		{
            flag=1;
            break;
        } 
    }
    if(flag)
        printf("ERROR\n");
    else
        printf("%d\n",sum);
    return 0;
}
