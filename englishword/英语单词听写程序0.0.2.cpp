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
int suiji();
void exit_();
int k=0;
int total_te=0,total_wr=0; 
struct word
{
    string chi,eng;
    int te,wr;
};
word wlist[10001]; 
int lis()
{
	int chi_maxlen=0,i;
	for(i=1;i<=k;i++)
	{
		if(chi_maxlen<wlist[i].chi.length()) chi_maxlen=wlist[i].chi.length();
	}
	printf("序号\t中文");
	for(i=1;i<=chi_maxlen+2;i++) printf(" ");
	printf("英文\n");
	for(int i=1;i<=k;i++)
	{
		cout<<i<<"\t"<<wlist[i].chi;
		for(int j=1;j<=chi_maxlen+3-wlist[i].chi.length();j++) printf(" ");
		cout<<wlist[i].eng<<endl;
	} 
	system("Pause");
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
	    fout <<endl<<b<<" "<<a<<" 0 0";
	    k++;
	    wlist[k].chi=a;
	    wlist[k].eng=b;
	    wlist[k].te=0;
	    wlist[k].wr=0;
	    total_wr+=5;
	    total_te+=5;
	    cout<<"添加大成功！"<<endl;
    }
}
int randnew(int left, int right)
{
  static unsigned int seed = 0;
  seed++;
  srand((unsigned) time(NULL) + seed * seed);
  return rand() % (right - left + 1) + left;
}
int cho()
{
	cout <<"请选择您要进行的操作"<<endl;
	cout <<"1.报英文听写中文   2.报中文听写英文" <<endl;
	cout <<"3.查看单词表       4.添加单词" <<endl;
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
		default : return 1;
	}
}
int suiji()
{
    int a=0,return_=0;
    do
    {
    	return_=randnew(1,total_te); 
	}while(return_>total_wr);
	while(return_>0) return_-=(wlist[++a].wr+5);
	return a;
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
		int a=suiji();                                             //随机数算法 
		cout << "第" << ++tim << "题" << " 中文为 " << wlist[a].chi << endl;
		string ans;
		cin >> ans;
		if(k==0) 
	{
		system("cls");
		cout<<"单词表无数据"<<endl;
		cout<<"已返回选择窗口" <<endl;
		system("Pause"); 
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
			wlist[a].te++;
			total_te++;
		}
		else
		{
			cout <<"很可惜答错了"<<endl;
			wlist[a].te++;
			wlist[a].wr++;
			total_te++;
			total_wr++;
			cout <<"正确的答案为 " << wlist[a].eng<<endl;;
		}
		
		if(tim%5==0) 
		{
		    cout<<"为防止数据丢失，自动保存数据"<<endl; 
		    exit_();
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
		system("Pause");
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
   	SetConsoleTitle ("英语单词听写程序    版本：0.0.2");
  	cout << "欢迎使用英语听写软件！\n!!!!!!!!!" << endl;
    cout << "当前版本为：" << VER <<endl;  
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
            system("Pause");
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
	int c,d;
//	fin.clear();
//  fin.seekg(0, ios::beg); 
	fin>>a;	
	if(a!=VER) 
	{
		cout << "word.list版本不匹配" << endl;
	 	cout << "为防止出现兼容性问题已停止程序" << endl;
		cout << "单词表版本：" << a;
		if(a=="0.0.1") 
		cout<<"\n请前往论坛下载0.0.1->0.0.2工具"<<endl;
		system("Pause");
		return 0;
	}
	cout << "检测到匹配的word.list文件" << endl; 
    while(fin >> a) 
    {
    	fin >> b >> c >> d;
		k++;
    	wlist[k].eng=a;
    	wlist[k].chi=b;
    	wlist[k].te=c;
    	wlist[k].wr=d;
    	total_te+=wlist[k].te+5;
    	total_wr+=wlist[k].wr+5;
	}
	cout << "单词表读取大成功！" << endl;
	int x=1;
	do
	{
		x=cho();
	} while(x!=1);
	exit_();
	return 0;
}
void exit_()
{
	ofstream fout("word.list");
	fout.seekp(0, ios::beg);
	fout<<VER<<endl;
	for(int i=1;i<=k;i++) 	    fout <<endl<<wlist[i].eng<<" "<<wlist[i].chi<<" "<<wlist[i].te<<" "<<wlist[i].wr;
	cout<<"保存文件成功！"<<endl;
	return ;
}
