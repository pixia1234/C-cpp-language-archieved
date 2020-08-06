#include<iostream>
#include<fstream> 
using namespace std;
struct node
{
	string name,passwd;
} user[1001];
void list(int k)
{
	for(int i=1;i<=k;i++)
	{
		int n=i,j;
		for(j=i;j<=k;j++)
	    {
	    	if(user[j].name<user[n].name) n=j;
		}
		string na,p;
		na=user[i].name;
		p=user[i].passwd;
		user[i].name=user[n].name;
		user[i].passwd=user[n].passwd;
		user[n].name=na;
		user[n].passwd=p;
	}
}
void list2(int i)
{
	if(i==0) return;
	cout<<user[i].name<<"       "<<user[i].passwd<<endl;
	list2(--i);
}
int main()
{
	ifstream fin ("user.config") ;
	if(!fin.is_open()) 
	{
	    ofstream fout ("user.config");
	    cout<<"没有用户文件，自动新建文件"<<endl;
		ifstream fin ("user.config") ;
	}
	string username,userpasswd;
	int i,k=0;
	bool flag;
	user[0].name="admin";
	user[0].passwd="admin";
	while(fin >> username)
	{
		fin >> userpasswd;
		k++;
		user[k].name=username;
		user[k].passwd=userpasswd;
	}
	while(1)
	{
		cout<<"输入0退出登陆程序"<<endl;
		cout<<"请输入用户名:"<<endl;
		cin>>username;
		if(username=="0") return 0;
		cout<<"请输入密码"<<endl;
		cin>>userpasswd;
		flag=true;
		for(i=0;i<=k;i++)
		{
			if(username==user[i].name&&userpasswd==user[i].passwd)
			{
				cout<<"登陆大成功！"<<endl;
				cout<<"您登陆的用户为："<<username<<endl;
				flag=false;
				break; 
			}
		}
		if(flag)
		{
			cout<<"用户名或密码错误"<<endl; 
			cout<<"请重新登录!"<<endl; 
		}
		else break;
	}
	if(i==0)
	{
		ofstream fout ("user.config");
		for(i=1;i<=k;i++) fout<<user[i].name<<endl<<user[i].passwd<<endl; 
		do
		{
			cout<<"请选择您的操作"<<endl;
			cout<<"1.添加用户 2.删除账户"<<endl<<"3.由大到小排列用户 4.由小到大排列用户"<<endl<<"5.逆序输出用户 6.查找指定用户的密码"<<endl<<"输入其他字符即为退出程序"<<endl;
			int x;
			flag=true;
			cin>>x;
			switch(x)
			{
				case 1:
				{
					k++;
					cout<<"请输入添加用户名"<<endl; 
					cin>>username;
					cout<<"请输入添加用户密码"<<endl;
					cin>>userpasswd;
					user[k].name=username;
					user[k].passwd=userpasswd;
					fout<<username<<endl<<userpasswd<<endl; 
					break;
				}
				case 2:
				{
					cout<<"序号        用户名         密码"<<endl;
					for(i=1;i<=k;i++) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					cout<<"请输入您想删除用户的序号"<<endl;
					cout<<"若输入序号不在范围内则退出"<<endl;
					cin>>i;
					if(i<=k&&i>0) 
					{
						for(int j=--k;j>=i;j--)
						{
							user[j].name=user[j+1].name;
							user[j].passwd=user[j+1].passwd;
						}
						ofstream fout ("user.config");
						for(i=1;i<=k;i++) fout<<user[i].name<<endl<<user[i].passwd<<endl;
						cout<<"删除大成功！"<<endl; 
					}
					break;
				}
				case 3:
				{
					list(k);
					cout<<"序号        用户名         密码"<<endl;
					for(i=k;i>=1;i--) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					break;
				} 
				case 4:
				{
					list(k);
					cout<<"序号        用户名         密码"<<endl;
					for(i=1;i<=k;i++) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					break;
				} 
				case 5 :
				{
					cout<<"序号        用户名         密码"<<endl;
					list2(k);
					break;
				}
				case 6:
				{
					cout<<"请输入指定用户的用户名"<<endl;
					string user_name;
					cin>>user_name;
					bool flag2=true;
					for(i=1;i<=k;i++) if(user_name==user[i].name)
					{
						cout<<"所查找用户的密码为："<<user[i].passwd<<endl;
						flag2=false;
					}  
					if(flag2) cout<<"没有该用户"<<endl;
					break;
				}
				default :
				{
					flag=false;
					break;
				}
			 } 
		} while(flag);
		return 0; 
	}
	else 
	{
		do
		{
			cout<<"请选择您的操作"<<endl;
			cout<<"1.进入程序 2.删除账户"<<endl<<"输入其他字符即为退出程序"<<endl;
			int x; 
			flag=true;
			cin>>x;
			switch(x)
			{
				case 1:
				{
					return 1;
					break;
				}
				case 2:
				{
					cout<<"您确定要删除您的帐户？【Y/N】"<<endl;
					char a;
					cin>>a;
					if(a=='Y'||a=='y')
					{
					    for(int j=--k;j>=i;j--)
						    {
							    user[j].name=user[j+1].name;
							    user[j].passwd=user[j+1].passwd;
						    }
						    ofstream ffout ("user.config");
						    for(i=1;i<=k;i++) ffout<<user[i].name<<endl<<user[i].passwd<<endl;
					    }	 
					cout<<"删除大成功！"<<endl;    
					return 0;
				}
				default :
				{
					flag=false;
					break;
				}
			}
		}while(flag);
		return 0;
	}
}

