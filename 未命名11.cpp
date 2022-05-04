#include<iostream>
using namespace std;
int main()
{
	int num[10],*p;
	for(int i=0;i<10;i++) cin>>num[i];
	p=&num[9];
	for(int i=1;i<=10;i++) 
	{
		cout<<*p<<" ";
		p--;
	}
	return 0;
}

