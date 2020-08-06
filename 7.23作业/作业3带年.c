#include<stdio.h> 
int run(int a,int b)
{
	int an=0,i;
	for( i=a;i<=b;i++) 
	{
	    if(!(i%4)&&(i%100)||!(i%400)) an++;
	    an++;
	}
	an%=7;
	return an; 
}
int main(){
	int mon[]={0,31,59,90,120,151,181,212,243,275,304,334,365};
	int a,b,c,ans;
	scanf("%d %d %d",&c,&a,&b);
	ans=(c>=2020?run(2020,c):run(c,2020)); 
	if((!(c%4)&&(c%100)||!(c%400))&& ((c>=2020&&a<=2&&b<=28)||(c<2020&&a>=2&&b>=29))) ans--;
	ans+=b+mon[a-1];
	ans++;
	ans%=7;
	if(!ans) ans=7;
	printf("%d",ans);
	return 0;
}4


