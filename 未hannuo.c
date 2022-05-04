#include<stdio.h>
void print(char x,char y)
{
	printf("%c->%c\n",x,y);
	return;
}
void mov(int n,char a,char b,char c)//n个盘子由atoc 
{
	if(n==1) print(a,c);//n=1是由a->c 
	else
	{
		mov(n-1,a,c,b);
		print(a,c);
		mov(n-1,b,a,c);	 
	}
	return ;
}
int main()
{
	int x;
	scanf("%d",&x);
	mov(x,'A','B','C');
	return 0;
}

