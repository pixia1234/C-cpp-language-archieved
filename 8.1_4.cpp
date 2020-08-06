#include<stdio.h>
int ans=0;
int queen(int an[],int k)
{
	int i,j;
	for(i=0;i<8;i++)
	{
		int in=0;
		for(j=0;j<k;j++) if(i==an[j]||i-an[j]==k-j||an[j]-i==k-j) 
		{
			in=1;break;
		}
		if(in) continue;
		an[j]=i;
		if(k==7) ans++;
		else queen(an,k+1);
	}
}
int main(){
	int an[8]={0};
	queen(an,0);
	printf("%d",ans);
	return 0;
}

