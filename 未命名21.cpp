#include<bits/stdc++.h>
using namespace std;
struct 
{
	int v,b;
	bool a;
}money[21];
int main()
{
	int n,c;
	for(int i=1;i<=n;i++) cin>>money[i].v>>money[i].b;
	int ans=0;
	for(int i=1;i<=n;i++) if(money[i].v>=c) 
	{
		ans+=money[i].b;
		money[i].a=false;
	}
	else money[i].a=true;
	for(int i=1;i<=n;i++)
	{
		if(money[i].a) continue;
		
	}
}
