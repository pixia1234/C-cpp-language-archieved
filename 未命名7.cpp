//10����to2���� 
#include<bits/stdc++.h>
using namespace std; 
int main()
{
	int n,i,j;
	cin>>n;
	for(i=0;pow(2,i)<=n;) i++;
	for(j=i-1;j>=0;j--) {
	    if(pow(2,j)<=n) 
	    {
	    	cout<<1;
	    	n-=pow(2,j);
		}
		else cout << 0;
	}
	cout << endl;
	return 0;
} 

