#include<stdio.h>
#include<math.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=2;i<=sqrt(n);i++) if(n%i==0)
	{
	printf("No");
	return 0;
    }
    printf("Yes");
    return 0;
}

