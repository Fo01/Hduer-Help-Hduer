#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main(){
double a,b,c;
scanf("%lf%lf%lf",&a,&b,&c);
if(a==0 && b==0 && c==0)
printf("Zero Equation");
else if(a==0 && b==0 && c!=0)
printf("Not An Equation");
else if(a==0 && b!=0)
printf("%.2lf",-1*c/b);
else if((b*b > 4*a*c) && a!=0){
printf("%.2lf\n",(-1*b+sqrt(b*b-4*a*c))/(2*a));
printf("%.2lf",(-1*b-sqrt(b*b-4*a*c))/(2*a));
}
else if((b*b < 4*a*c) && a!=0){
if(b == 0){
printf("0.00+%.2lfi\n",sqrt(4*a*c-b*b)/(2*a));
printf("0.00-%.2lfi",sqrt(4*a*c-b*b)/(2*a));
}
else{
printf("%.2lf+%.2lfi\n",-1*b/(2*a),sqrt(4*a*c-b*b)/(2*a));
printf("%.2lf-%.2lfi",-1*b/(2*a),sqrt(4*a*c-b*b)/(2*a));
}
}
else if((b*b == 4*a*c) && a!=0)
printf("%.2lf",-1*b/(2*a));
} 
