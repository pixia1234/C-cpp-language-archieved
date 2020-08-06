//p3740
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	int loc[m+1][3];
	for(int i=1;i<=m;i++) 	    scanf("%d%d",&loc[i][1],&loc[i][2]);
	bool mar[n+1];
	memset(mar,0,(n+1)*sizeof(bool));
	for(int i=m;i>=1;i--)
	{
		for(int j=loc[i][1];j<=loc[i][2];j++)
		{
			if(mar[j]==0) 
			{
				ans++;
				for(int k=loc[i][1];k<=loc[i][2];k++) mar[k]=1;
				break;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

