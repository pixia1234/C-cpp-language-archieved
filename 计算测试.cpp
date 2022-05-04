#include<iostream>
#include<cstdlib>
#include<ctime> 
#include<cmath>
#include<Windows.h>
using namespace std;
int jia(int k);
int jian(int k);
int cheng(int k);
int chu(int k);
int main()
{
	cout<<"欢迎使用本程序"<<endl;
	cout<<"请输入本程序使用的难度等级(1-5)"<<endl;
	int n,mark=0;
	cin>>n;
	time_t second1;
	second1 = time(0);
		for(int i=1;i<=10;i++)
		{ 
		    cout<<"第"<<i<<"题:" ;
		    int num,return_;
		    srand(time(0));
		    num=1+rand()%4; 
		    switch(num)
			{
		    	case 1:
		    	{
		    		return_=jia(n);
		    		break;
				}
				case 2:
				{
					return_=jian(n);
				    break;
				}
				case 3:
				{
					return_=cheng(n);
					break;
				}
				case 4:
				{
					return_=chu(n);
					break;
				}
			} 
	    if(num) mark+=10;
	   }
	cout<<"您的分数为："<<mark<<endl;
	srand(time(0));
	time_t second2;
	second2=(time(0));
	printf("所用的时间为：%d seconds",second2-second1);
	system("Pause"); 
	return 0;
}
int jia(int k)
{
	int a,b,ans;
	srand(time(0));
	a=pow(10,k-1)+rand()%(int)(pow(10,k));
	b=pow(10,k-1)+rand()%(int)(pow(10,k));
	ans=a+b;
	cout<<a<<"+"<<b<<"=";
	int ans_;
	cin>>ans_;
	if(ans_==ans) 
	{
	    cout<<"答对了"<<endl;
	    return 1;
	}
	else 
	{
	    cout<<"答错了,正确答案为" <<ans<<endl;
	    return 0;
	}
}
int jian(int k)
{
	int a,b,ans;
	srand(time(0));
	a=pow(10,k-1)+rand()%(int)pow(10,k);
	b=pow(10,k-1)+rand()%(int)pow(10,k);
	ans=a+b;
	cout<<ans<<"-"<<b<<"=";
	int ans_;
	cin>>ans_;
	if(ans_==a) 
	{
	    cout<<"答对了"<<endl;
	    return 1;
	}
	else 
	{
	    cout<<"答错了,正确答案为" <<a<<endl;
	    return 0;
	}
}
int cheng(int k)
{
	int a,b,ans;
	srand(time(0));
	a=pow(3,k-1)+rand()%(int)pow(3,k);
	b=pow(3,k-1)+rand()%(int)pow(3,k);
	ans=a*b;
	cout<<a<<"*"<<b<<"=";
	int ans_;
	cin>>ans_;
	if(ans_==ans) 
	{
	    cout<<"答对了"<<endl;
	    return 1;
	}
	else 
	{
	    cout<<"答错了,正确答案为" <<ans<<endl;
	    return 0;
	}
}
int chu(int k)
{
	int a,b,ans;
	srand(time(0));
	a=pow(3,k-1)+rand()%(int)pow(3,k);
	b=pow(3,k-1)+rand()%(int)pow(3,k);
	ans=a*b;
	cout<<ans<<"/"<<b<<"=";
	int ans_;
	cin>>ans_;
	if(ans_==a) 
	{
	    cout<<"答对了"<<endl;
	    return 1;
	}
	else 
	{
	    cout<<"答错了,正确答案为" <<a<<endl;
	    return 0;
	}
}
