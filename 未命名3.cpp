#include<cstdio>
#include<cstring>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
#include<map>
#include<vector>
using namespace std;

struct Elem{ //元素 
	string name; //名称 
	int num; //个数 
	Elem(string _name, int _num): name(_name), num(_num){}
};

int toNumber(string str, int &pos){ //从str的pos位置开始，得到一个数字 
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
	
	while(getline(ss, item, '+')){ //获取每一个化学式，如 32Ba((OH)2(CO3)2)3 
	 
		vector<Elem> arr; //存储化学式的分解序列， 如 Ba、(、(、O、H、)、(、C、O、)、) 
		int factor=1; //整个化学式的系数，默认为1 
		int i=0;
		
		if(isdigit(item[i])) factor=toNumber(item,i); //计算化学式系数
		 
		while(i<item.size()){
			if(isdigit(item[i])){ //处理数字
				int num=toNumber(item,i);
				if(arr[arr.size()-1].name==")"){ //序列最后一个元素是右括号 
					int j=arr.size()-1;
					arr[j].name="*"; //将右括号标记为*，忽略它的存在 
					while(arr[--j].name!="("){
						arr[j].num*=num;
					}
					arr[j].name="*"; //将左括号标记为*，忽略它的存在 
				}
				else arr[arr.size()-1].num*=num; //序列最后一个元素是元素名称 
			}
			else if(item[i]=='('){ //处理左括号 
				arr.push_back(Elem("(", 0));  //括号加入到序列中
				i++;
			}
			else if(item[i]==')'){ //处理右括号
				arr.push_back(Elem(")", 0));  //括号加入到序列中
				if(i+1==item.size() || !isdigit(item[i+1])) item.insert(i+1,"1"); //考虑到右括号右边可能不出现数字，补充底数1 
				i++;
			}
			else if(isupper(item[i])){ //处理大写字母 
				//得到元素名称 
				string name="";
				name+=item[i]; //大写字目 
				i++;
				if(islower(item[i])){ //小写字母 
					name+=item[i];
					i++;
				}
				arr.push_back(Elem(name,1)); //名称加入到序列中 
			}
		}
		
		for(int i=0; i!=arr.size(); ++i){ //将“元素->个数”保存到map中 
			if(arr[i].name=="*") continue; //忽略序列中括号的存在 
			mp[arr[i].name]+=arr[i].num*factor;
		}
		
	}
	
}

bool judge(map<string, int> &left, map<string, int> &right){ //判断两个map是否相同 
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
		getline(ss, lstr,'='); //得到等号左边的字符串 
		getline(ss, rstr); //得到等号右边的字符串 
	
		calc(lstr, left); //计算左字符串 
		calc(rstr, right);
		
		if(judge(left, right)) cout<<"Y"<<endl;
		else cout<<"N"<<endl; 
	}
	return 0;
}
