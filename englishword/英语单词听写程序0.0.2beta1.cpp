#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream>
#include<Windows.h>
#define VER "0.0.2"
#define PASSWD "pixia1234" 
using namespace std;
int etc();
int cte();
int add();
int lis();
int cho();
int set();
int set_check();
int k=0;
int beta_cho();
struct word
{
    string chi,eng;
};
word wlist[10001]; 
int beta_cho()
{
	
}
int set_check()
{
	ifstream betain("beta.passwd");
	if(!betain.is_open()) return 0;
	string a;
	betain>>a;
	if(a!=PASSWD) 	return 2; 
    return 1;
}
int set()
{
	cout<<"正在进行 高级设置"<<endl;
	if(set_check()!=1){
	    cout<<"请输入beta密码"<<endl;
    	string a;
    	cin>>a;
    	if(a==PASSWD) 
    	{
	 	    cout<<"beta版本解锁成功！"<<endl;
		    ofstream betaout("beta.passwd");
			if(!betaout)  //检查是否打开成功
			{
            cout <<"创建文件失败！\n";
            return 0; 
		    }
		    betaout<<a<<endl;
		    cout<<"请重新进入" <<endl;
		    return 0;
    	}
    	else 
    	{
    		system("cls");
    		cout<<"beta密码错误！"<<endl;
    		cout<<"!!!!！\n解锁失败" <<endl;
    		return 0; 
    	}
	}
	return beta_cho();
}
int lis()
{
	cout <<"序号"<<"   "<<"中文    " <<"英文" <<endl; 
	for(int i=1;i<=k;i++)
	{
		cout << i << "   " <<  wlist[i].chi << "   " << wlist[i].eng << endl;
	} 
	cout << "输入任意值返回" << endl; 
	int x;
	cin >> x;
	system("cls");
	return 0;
}
int add()
{
    cout << "请输入单词的中文，英文，中间用空格隔开" <<endl;
    cout << "返回请输入0" << endl;
    ofstream fout("word.list",ios::app);
    string a,b;
    while(1)
    {
    	cin >> a;
    	if(a=="0") 
		{
			system("cls");
			return 0;
	    }
	    cin >>b;
	    fout <<endl<<b<<" "<<a;
	    k++;
	    wlist[k].chi=a;
	    wlist[k].eng=b;
	    cout<<"添加大成功！"<<endl;
    }
}
int cho()
{
	cout <<"请选择您要进行的操作"<<endl;
	cout <<"1.报英文听写中文   2.报中文听写英文" <<endl;
	cout <<"3.查看单词表       4.添加单词" <<endl;
	cout <<"5.高级设置" <<endl; 
	cout <<"请直接输入操作的序号\n退出程序请直接输入任意其他字符" <<endl;
	cout <<"软件版本为：" <<VER<< endl; 
	int a;
	cin>>a;
	system("cls");
	switch(a)
	{
		case 1: return etc();
		case 2: return cte();
		case 3: return lis();
		case 4: return add();
		case 5: return set();
		default : return 1;
	}
}
int cte()
{
	cout<<"正在进行 报中文听写英文操作"<<endl<<"!!!\n";
	cout<<"请直接输入英文" <<endl;
	cout<<"退出请输入0" <<endl;
	int tim=0;
	while(1)
	{
	    srand(time(0));
		int a=1+rand()%k;	
		cout << "第" << ++tim << "题" << " 中文为 " << wlist[a].chi << endl;
		string ans;
		cin >> ans;
		if(k==0) 
	{
		system("cls");
		cout<<"单词表无数据"<<endl;
		cout<<"已返回选择窗口" <<endl;
		return 0;
	}
		if(ans=="0")
		{
			system("cls");
		    return 0;
		}
		if(ans==wlist[a].eng)
		{
			cout <<"恭喜你答对了"<<endl;
			continue; 
		}
		else
		{
			cout <<"很可惜答错了"<<endl;
			cout <<"正确的答案为 " << wlist[a].eng<<endl;;
		}
	} 
}
int etc()
{
	cout << "正在进行 报英文听写中文操作" <<endl << "!!!\n";
	cout << "由于判断存在偏差，请自行判断是否正确" <<endl;
	cout << "若正确请输入1，错误输入0，返回请输入任意其他字符" <<endl;
	if(k==0) 
	{
		system("cls");
		cout << "单词表无数据" << endl;
		cout << "已返回选择窗口" << endl;
		return 0;
	}
	int tim=0;
	while(1)
	{
		srand(time(0));
		int a=1+rand()%k,m;
		cout << " 第" << ++tim << "题" << "英文为" << wlist[a].eng << endl;
		cin>>m;
		cout << "      中文为" << wlist[a].chi << endl;
		cin>>a;
		if(a==1)
		{
			cout << "恭喜你答对了" << endl; 
			continue;
		}
		if(a==0) 
		{
		    cout << "很可惜答错了" << endl;
			continue; 
		}
		system("cls");
		return 0;
	}
}
int main()
{
	if(set_check()!=1){
    	SetConsoleTitle ("英语单词听写程序    版本：0.0.2");
    	cout << "欢迎使用英语听写软件！\n!!!!!!!!!" << endl;
    	cout << "当前版本为：" << VER <<endl;  
    }
    else
	{
		if(set_check()==2) cout<<"beta密码错误！"<<endl;
	    cout<<"beta.passwd读取大成功！"  <<endl;
		SetConsoleTitle ("英语单词听写程序    版本：0.0.2 beta");
    	cout << "欢迎使用英语听写软件！\n!!!!!!!!!" << endl;
    	cout << "当前版本为：" << VER <<" for beta"<<endl;
		
	} 
    ifstream fin("word.list");
    if( !fin.is_open())
    {
    	cout << "找不到word.list文件（单词表）" << endl; 
    	int x;
    	cout<<"是否新建word.list文件？(按1确认，其他字符退出)" <<endl; 
    	cin>>x;
		if(x==1) 
		{
			ofstream fout("word.list");
			if(!fout)  //检查是否打开成功
			{
            cout <<"创建文件失败！\n";
            return 0; 
		    }
		    fout<<VER<<endl;
		    cout<<"创建文件大成功！\n";
		    do
	        {
		        x=cho();
	        } while(x!=1);
	        return 0;
	    }
		else return 0;
	}
	string a,b;
//	fin.clear();
//  fin.seekg(0, ios::beg); 
	fin>>a;	
	if(a!=VER) 
	{
		cout << "word.list版本不匹配" << endl;
	 	cout << "为防止出现兼容性问题已停止程序" << endl;
		cout << "单词表版本：" << a;
		cin >> a; 
		return 0;
	}
	cout << "检测到匹配的word.list文件" << endl; 
    while(fin >> a) 
    {
    	fin >> b;
		k++;
    	wlist[k].eng=a;
    	wlist[k].chi=b;
	}
	cout << "单词表读取大成功！" << endl;
	int x=1;
	do
	{
		x=cho();
	} while(x!=1);
	return 0;
}
