#include<stdio.h>
int main()
{
	char a[]={"I Love C Programs"};
	char b[]={"我 爱 科 技 未 来"};
	int x=sizeof(a),y=sizeof(b);
	int sum=x>y?x:y,j;
	for(j=1;j<=sum-1;j++) printf("*");
	printf("\n");
	printf("%s\n%s\n",a,b);
	for(j=1;j<=sum-1;j++) printf("*");//字符数组末尾带“\0”故需要-1 
	printf("\n");
	return 0;
}

