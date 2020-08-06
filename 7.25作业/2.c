#include<stdio.h>
int main(){
	double ans=0;
	int i;
	for(i=1;i<=21;i++) ans+=(double)(i+1)/i;
	printf("%lf",ans);
	return 0; 
}

