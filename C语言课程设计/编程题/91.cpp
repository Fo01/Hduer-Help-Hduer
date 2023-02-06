#include<stdio.h>
#include<math.h>
#define pr(a) printf("%d",a);
#define sc(a) scanf("%d",&a);
int main()
{
    int a[10][10],n,i,j,max,maxj,flag,count=0;
    sc(n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            sc(a[i][j]);
    for(i=0;i<n;i++)
    {
        max=a[i][0];
        maxj=0;
        for(j=1;j<n;j++) 
        {
            if(max<=a[i][j])    
            {
                max=a[i][j];
                maxj=j;
            }
        }
        flag=1;      
        for(j=0;j<n;j++)
        {
            if(a[j][maxj]<max)              
            {
                flag=0;
                break;
            }
        }
        if(flag==1)        
        {
            count++;         
            printf("%d %d",i,maxj);
        }
    } 
    if(count==0) printf("NONE");
    return 0;
}
