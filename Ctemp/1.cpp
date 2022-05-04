/*
题目描述
John和朋友们在玩纸牌游戏，他们一共有m个人（包括John）。他们的纸牌比较特殊，一共有n*m张牌，
牌号分别为1,2,…,n*m，没有牌号相同的牌。每个人先拿到n张牌，然后，每一轮，每个人出一张牌，谁最大则谁赢得这一轮。现在已知John手中的n张牌，计算他最少能赢得多少轮。

输入格式
第一行为两个整数m和n，2≤m≤20，1≤n≤50；第二行有n个正整数，表示John手中的n张牌的数值。

输出格式
仅一个整数，表示John最少能赢的次数。
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,pai[52],ans=0,sum=0;
	cin>>m>>n;
  for(int i=1;i<=n;i++) scanf("%d",&pai[i]);
  sort(pai+1,pai+n+1);
  for(int i=n,j=m*n;i>0;i--,j--)
        {
		if(pai[i]==j)
			sum++;
		else
			{
			sum--;
			i++;
			}
		ans=max(ans,sum);
		}
	cout<<ans<<endl;
	return 0;
}
