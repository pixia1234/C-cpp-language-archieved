#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;

struct Elem{ //Ԫ�� 
	string name; //���� 
	int num; //���� 
	Elem(string _name, int _num): name(_name), num(_num){}
};

int toNumber(string str, int &pos){ //��str��posλ�ÿ�ʼ���õ�һ������ 
	int num=0;
	while(isdigit(str[pos])){
		num=num*10+str[pos]-'0';
		pos++;
	}
	return num; 
} 

void calc(string &str, map<string, int> &mp){
	stringstream ss(str);
	string item;
	
	while(getline(ss, item, '+')){ //��ȡÿһ����ѧʽ���� 32Ba((OH)2(CO3)2)3 
	 
		vector<Elem> arr; //�洢��ѧʽ�ķֽ����У� �� Ba��(��(��O��H��)��(��C��O��)��) 
		int factor=1; //������ѧʽ��ϵ����Ĭ��Ϊ1 
		int i=0;
		
		if(isdigit(item[i])) factor=toNumber(item,i); //���㻯ѧʽϵ��
		 
		while(i<item.size()){
			if(isdigit(item[i])){ //��������
				int num=toNumber(item,i);
				if(arr[arr.size()-1].name==")"){ //�������һ��Ԫ���������� 
					int j=arr.size()-1;
					arr[j].name="*"; //�������ű��Ϊ*���������Ĵ��� 
					while(arr[--j].name!="("){
						arr[j].num*=num;
					}
					arr[j].name="*"; //�������ű��Ϊ*���������Ĵ��� 
				}
				else arr[arr.size()-1].num*=num; //�������һ��Ԫ����Ԫ������ 
			}
			else if(item[i]=='('){ //���������� 
				arr.push_back(Elem("(", 0));  //���ż��뵽������
				i++;
			}
			else if(item[i]==')'){ //����������
				arr.push_back(Elem(")", 0));  //���ż��뵽������
				if(i+1==item.size() || !isdigit(item[i+1])) item.insert(i+1,"1"); //���ǵ��������ұ߿��ܲ��������֣��������1 
				i++;
			}
			else if(isupper(item[i])){ //�����д��ĸ 
				//�õ�Ԫ������ 
				string name="";
				name+=item[i]; //��д��Ŀ 
				i++;
				if(islower(item[i])){ //Сд��ĸ 
					name+=item[i];
					i++;
				}
				arr.push_back(Elem(name,1)); //���Ƽ��뵽������ 
			}
		}
		
		for(int i=0; i!=arr.size(); ++i){ //����Ԫ��->���������浽map�� 
			if(arr[i].name=="*") continue; //�������������ŵĴ��� 
			mp[arr[i].name]+=arr[i].num*factor;
		}
		
	}
	
}

bool judge(map<string, int> &left, map<string, int> &right){ //�ж�����map�Ƿ���ͬ 
	if(left.size()!=right.size()) return false;
	for(map<string, int>::iterator it=left.begin(); it!=left.end(); ++it){
		if(right[it->first]!=it->second) return false;
	}
	return true;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		map<string, int> left, right;
		string str, lstr, rstr;
		cin>>str;
		stringstream ss(str);
		getline(ss, lstr,'='); //�õ��Ⱥ���ߵ��ַ��� 
		getline(ss, rstr); //�õ��Ⱥ��ұߵ��ַ��� 
	
		calc(lstr, left); //�������ַ��� 
		calc(rstr, right);
		
		if(judge(left, right)) cout<<"Y"<<endl;
		else cout<<"N"<<endl; 
	}
	return 0;
}
