#include<stdio.h>
int main()
{
	char a[]={"I Love C Programs"};
	char b[]={"�� �� �� �� δ ��"};
	int x=sizeof(a),y=sizeof(b);
	int sum=x>y?x:y,j;
	for(j=1;j<=sum-1;j++) printf("*");
	printf("\n");
	printf("%s\n%s\n",a,b);
	for(j=1;j<=sum-1;j++) printf("*");//�ַ�����ĩβ����\0������Ҫ-1 
	printf("\n");
	return 0;
}

