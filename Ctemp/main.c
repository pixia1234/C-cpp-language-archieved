#include <stdio.h>
#include <stdlib.h>
int a;
int main() {
	extern int power(int);
	int d,m;
	scanf("%d%d",&a,&m);
	d=power(m);
	printf("%d**%d=%d\n",a,m,d);
	return 0;
}
