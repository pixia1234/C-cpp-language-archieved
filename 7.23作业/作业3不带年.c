#include<stdio.h>
int main(){
	int mon[]={0,31,60,91,121,152,182,213,244,274,305,335,366};
	int a,b,ans;
	scanf("%d %d",&a,&b);
	ans=2+b+mon[a-1];
	ans%=7;
	if(!ans) ans=7;
	printf("%d",ans);
	return 0;
}

