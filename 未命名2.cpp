#include <bits/stdc++.h>
using namespace std;
int dx[]={0,1,0,-1,1,1,-1,-1},dy[]={1,0,-1,0,1,-1,1,-1};
int main()
{
	int n,i,j,num[10]={0},loc[1010][2];
	cin>>n;
	for(i=1;i<=n;i++) cin>>loc[i][0]>>loc[i][1];
	for(i=1;i<=n;i++)
	{
		bool flag=true;
		for(j=0;j<=3;j++)
		{
			bool flag2=true;
			for(int k=1;k<=n;k++) if(loc[k][0]==loc[i][0]+dx[j]&&loc[k][1]+dy[j]==loc[i][1])
			{
				flag2=false;
				break;
			}
			if(flag2)
			{
				flag=false;
				break;
			}
		}
		if(flag)
		{
			int a=0;
			for(j=4;j<=7;j++)
			{
				for(int k=1;k<=n;k++) if(loc[k][0]==loc[i][0]+dx[j]&&loc[k][1]+dy[j]==loc[i][1])
				{
					a++;
					break;
				}
			}
			num[a]++;
		}
	}
	for(i=0;i<5;i++) cout<<num[i]<<endl;
	return 0;
}

