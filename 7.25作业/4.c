
#include<stdio.h>
int main(){
	int i;
	for(i=1;i<=1000;i++)
	{
		int a=i,wei=1;
		do 
		{
			a/=10;
			wei*=10;
		}while(a);
		if(((i-1)*i)%wei==0) printf("%-6d",i);
	}
	return 0;
}
