#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int k,n;
    int i,j;
    int a[10][10];
    int point[4];
    int line=0,count=0,error=0;
    char op='*';
	int fresh=(int) op;//存储星号
	sc(n);
	getchar();//消去回车
	n=2*n+1;
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			op=getchar();
			a[i][j]=(int) op;
			getchar();//消去空格或回车
		}
	}
	sc(k);
	while(line<k)
	{
		scanf("%d %d %d %d",&point[0],&point[1],&point[2],&point[3]);
		if(a[point[0]][point[1]]==a[point[2]][point[3]])
		{
			if(a[point[0]][point[1]]!=fresh)
			{
				a[point[0]][point[1]]=fresh;
				a[point[2]][point[3]]=fresh;
                count++;
                if(count==2*(n-1))
                {
                    break;
                }
				for(i=1;i<n;i++)
				{
					printf("%c",a[i][1]);
					for(j=2;j<n;j++)
					{
						printf(" %c",a[i][j]);
					}
					printf("\n");
				}
			}
			else
			{
				printf("Uh-oh\n");
				error++;
				if(error==3)
				{
					break;
				}
			}
		}
		else
		{
			printf("Uh-oh\n");
            error++;
            if(error==3)
            {
                break;
            }
		}
        line++;
	}
	if(error==3)
	{
		printf("Game Over\n");
	}
	if(count==2*(n-1))
	{
		printf("Congratulations!\n");
	}
}
