//Ô¼Éª·ò
#include<stdio.h>
int main(){
	int n,m,a=1,i,j,pan[101]={0};
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<m;)
		{
			if(pan[a]==0) j++;
			a++;
			if(a>n) a=1;
	    }
	    while(pan[a]==1) 
	    {
	    	a++;
	    	if(a>n) a=1;
		}
	    printf("%d ",a);
	    pan[a]=1;
	}
	return 0;
}

