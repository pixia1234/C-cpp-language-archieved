#include<stdio.h>
int main(){
	int i=0,sum=0;
	while(i<=1000)
	{
		int x;
		scanf("%d",&x);
		sum+=x;
		i++;
		if(x>=1e6) break;
	}
	printf("%d %f",i,(float)sum/i);
	return 0;
}

