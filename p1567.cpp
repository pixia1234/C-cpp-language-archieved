#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,num[100001],ans=0,ans2=0;
	cin>>n;
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	for(int i=1;i<n;i++)
	{
		if(num[i]<num[i+1]) ans2++;
		else ans2=1;
		if(ans2>ans) ans=ans2;
	}
	cout<<ans<<endl;
	return 0;
}
