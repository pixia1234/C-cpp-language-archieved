#include<stdio.h>
#include<string.h> 
int main()
{
    char s[1001];
    int i,ans=0,flag=0,flag2;
    gets(s);
    for(i=0;i<strlen(s);i++)
    {
    	if(s[i]==' ') flag2=0;
    	else flag2=1;
    	if(flag!=flag2) 
    	{
    		if(flag2==0) ans++; 
    		flag=flag2;
		}
	}
	printf("%d",++ans);
}
