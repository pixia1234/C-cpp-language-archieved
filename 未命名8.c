#include <stdio.h>
int main()
{
	int i=3,z,x,y;
	z=(i++)+(i++)+(i++);
	printf("%d %d ",z,i);
	x=y=3;
	z=x+++y;
	printf("%d %d %d",z,x,y);
	z=-x+++y;
	printf("%d %d %d",z,x,y);
}

