#include<stdio.h>
void com(int le,int ri,int array[]); 
int main(){
	int a[10],i;
	for(i=0;i<10;i++) scanf("%d",&a[i]);
    com(0,9,a);
	for(i=0;i<10;i++) printf("%d ",a[i]);
}
void com(int le,int ri,int array[])
{
	int i=le,j=ri;
	int middle,temp;
	middle=array[(le+ri)/2];
	do
	{
		while(array[i]<middle&&(i<ri)) i++;
		while(array[j]>middle&&(j>le)) j--;
		if(i<=j)
		{
			temp=array[i];
			array[i]=array[j];
			array[j]=temp;
			i++;
			j--;
		}
	}while(i<=j);
	if(le<j) com(le,j,array);
	if(ri>j) com(i,ri,array);
}

