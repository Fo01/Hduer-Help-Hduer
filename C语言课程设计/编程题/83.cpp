#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);

int main()
{
    int n;
    int s[1009],a[1009],i,j; 
	sc(n);
    for(i=1;i<=n;i++)    
    {
        scanf("%d",&s[i]);
        a[i]=100;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(s[i]<=a[j])
            {
                printf("%d %d\n",s[i],j);
                a[j]=a[j]-s[i];
                break;
            }
        }
    }
    
    for(j=1;j<=n;j++)
    {
        if(a[j]==100) break;
    }
    
    if(j<=n) printf("%d",j-1);  
    else printf("%d",n);
    return 0;
}
