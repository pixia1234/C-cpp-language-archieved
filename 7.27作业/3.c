/*
��֪��������n��Ԫ�أ����ǰ���С�������С�����һ����x������������������С�
*/
//���û͵�� 
#include <stdio.h>
int main(){
	int n,x,num[1001],i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	scanf("%d",&x);
	if(x<=num[1]) 
	{
		for(i=n;i>=1;i--) num[i+1]=num[i];
		num[1]=x;
	}
	else if(x>=num[n]) num[n+1]=x;
	else
	{
		for(i=1;i<n;i++) 
		if(x>=num[i]&&x<=num[i+1]) 
		    {
		    for(j=n;j>=i+1;j--) num[j+1]=num[j];
			num[i+1]=x;
			break;
		    }
	}
	for(i=1;i<=n+1;i++) printf("%d ",num[i]);
	return 0;
}

