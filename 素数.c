#include<stdio.h>
int main(){
	int a,num[10001],i,j;
	for(i=2;i<=10000;i++) num[i]=1;
	for(i=2;i<5000;i++) 
	{
		if(num[i]) 
		{
			for(j=2;i*j<=10000;j++) num[i*j]=0;
			printf("%d\t",i);
		}
	}
	return 0;
}

