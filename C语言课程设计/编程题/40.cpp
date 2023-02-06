#include<stdio.h>
#include<math.h>
#define sc(a)  scanf("%d",&a)
#define scd(a) scanf("%lf",&a)
#define pr(a)  printf("%d",a)
#define prd(a) printf("%lf",a)

int main()
{
	char s[12];
	int i=0,s1,s2,s3,s4;
	s1=0;s2=0;s3=0;s4=0;
	for(i=0;i<10;i++)
	{
		s[i]=getchar();
		if (s[i]>='a'&&s[i]<='z'||s[i]>='A'&&s[i]<='Z') s1++;
		else if (s[i]==' '||s[i]=='\n') s2++;
		else if (s[i]>='0'&&s[i]<='9') s3++;
		else s4++;
//		printf("letter = %d, blank = %d, digit = %d, other = %d",s1,s2,s3,s4);
	}
	printf("letter = %d, blank = %d, digit = %d, other = %d",s1,s2,s3,s4);
}
