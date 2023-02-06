#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;

    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

char *search(char *s,char *t)
{
    int i=0,j=0,flag=1,mask;  
    while(s[i]!='\0')
	{
        flag=1;
        j=0;      
        mask=i;     
        while(t[j]!='\0'){
            if(s[i]!=t[j]){
                flag=0;     
                break;
            }else{         
                i++;
                j++;
            }
            
        }
        if(flag)       
            break;         
        i++;
    }
        if(flag)   
            return s+mask;
        else    
            return NULL;
}
