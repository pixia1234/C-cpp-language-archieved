/*
��n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m����
*/ 
//͵�˵��� 
#include<stdio.h> 
int main()
{
	int n,m,num[100001],i;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++) scanf("%d",&num[i]);
	for(i=1;i<=m;i++) printf("%d ",num[n-m+i]);
	for(i=1;i<=n-m;i++) printf("%d ",num[i]);
	return 0; 
}

