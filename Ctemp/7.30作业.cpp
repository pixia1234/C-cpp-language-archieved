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
	    cout<<"û���û��ļ����Զ��½��ļ�"<<endl;
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
		cout<<"����0�˳���½����"<<endl;
		cout<<"�������û���:"<<endl;
		cin>>username;
		if(username=="0") return 0;
		cout<<"����������"<<endl;
		cin>>userpasswd;
		flag=true;
		for(i=0;i<=k;i++)
		{
			if(username==user[i].name&&userpasswd==user[i].passwd)
			{
				cout<<"��½��ɹ���"<<endl;
				cout<<"����½���û�Ϊ��"<<username<<endl;
				flag=false;
				break; 
			}
		}
		if(flag)
		{
			cout<<"�û������������"<<endl; 
			cout<<"�����µ�¼!"<<endl; 
		}
		else break;
	}
	if(i==0)
	{
		ofstream fout ("user.config");
		for(i=1;i<=k;i++) fout<<user[i].name<<endl<<user[i].passwd<<endl; 
		do
		{
			cout<<"��ѡ�����Ĳ���"<<endl;
			cout<<"1.����û� 2.ɾ���˻�"<<endl<<"3.�ɴ�С�����û� 4.��С���������û�"<<endl<<"5.��������û� 6.����ָ���û�������"<<endl<<"���������ַ���Ϊ�˳�����"<<endl;
			int x;
			flag=true;
			cin>>x;
			switch(x)
			{
				case 1:
				{
					k++;
					cout<<"����������û���"<<endl; 
					cin>>username;
					cout<<"����������û�����"<<endl;
					cin>>userpasswd;
					user[k].name=username;
					user[k].passwd=userpasswd;
					fout<<username<<endl<<userpasswd<<endl; 
					break;
				}
				case 2:
				{
					cout<<"���        �û���         ����"<<endl;
					for(i=1;i<=k;i++) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					cout<<"����������ɾ���û������"<<endl;
					cout<<"��������Ų��ڷ�Χ�����˳�"<<endl;
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
						cout<<"ɾ����ɹ���"<<endl; 
					}
					break;
				}
				case 3:
				{
					list(k);
					cout<<"���        �û���         ����"<<endl;
					for(i=k;i>=1;i--) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					break;
				} 
				case 4:
				{
					list(k);
					cout<<"���        �û���         ����"<<endl;
					for(i=1;i<=k;i++) cout<<i<<"        "<<user[i].name<<"         "<<user[i].passwd<<endl;
					break;
				} 
				case 5 :
				{
					cout<<"���        �û���         ����"<<endl;
					list2(k);
					break;
				}
				case 6:
				{
					cout<<"������ָ���û����û���"<<endl;
					string user_name;
					cin>>user_name;
					bool flag2=true;
					for(i=1;i<=k;i++) if(user_name==user[i].name)
					{
						cout<<"�������û�������Ϊ��"<<user[i].passwd<<endl;
						flag2=false;
					}  
					if(flag2) cout<<"û�и��û�"<<endl;
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
			cout<<"��ѡ�����Ĳ���"<<endl;
			cout<<"1.������� 2.ɾ���˻�"<<endl<<"���������ַ���Ϊ�˳�����"<<endl;
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
					cout<<"��ȷ��Ҫɾ�������ʻ�����Y/N��"<<endl;
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
					cout<<"ɾ����ɹ���"<<endl;    
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

