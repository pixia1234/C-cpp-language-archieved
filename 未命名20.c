#include<stdio.h>
int main()
{
	int a[10],i,itemp,ipos;
	for(i=0;i<10;i++) scanf("%d",&a[i]);
	for(i=1;i<10;i++)
	{
		itemp=a[i];
		ipos=i-1;
		while((ipos>=0)&&itemp<a[ipos])
		{
			a[ipos+1]=a[ipos];
			ipos--;
		}
		a[ipos+1]=itemp;
	}
	for(i=0;i<10;i++) printf("%d ",a[i]);
}

