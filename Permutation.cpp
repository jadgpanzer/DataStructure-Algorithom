#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count = 1;
/*ȫ���е�ʵ�������ν���iλ�����һλ֮���ÿ�������н�����֮�󽫵�i+1λ�����һλ֮���ÿ�������н���*/
/*������ǲ��õݹ�ķ�ʽ����*/
void permutation(string str,int start,int end){
	//strΪҪ���������У�startΪ��㣬��ʼΪ0��endΪ�������յ㣬��ʼΪ�ַ����ĳ��� 
	
	//����޷������ˣ��������أ�������յ����н�� 
	if(start == end-1){
		cout<<"��"<<count++<<"�飺"<<str<<'\n';
		return ;
	}
	else{
		//�ڱ��㽫start��end֮���ÿ��Ԫ�ؽ�����Ȼ������һ�㽫start+1��end֮���ÿ��Ԫ�ؽ��� 
		for(int i = start ; i < end ; i++){
			swap(str[i],str[end-1]);
			permutation(str,start+1,end);
			swap(str[i],str[end-1]);
		}
	}
	return ;
}
/*�ǵݹ鷽��ʵ�ֵ�ȫ����*/
void _permutation_(string str,int start,int end){
	vector<string> stk;
	int count = 1 ;
	for(int i = 0 ; i < end ; i++){
		swap(str[i],str[end-1]);
		stk.push_back(str);
		swap(str[i],str[end-1]);
	}
	for(int i = 1 ; i < str.length() ; i++){
		vector<string> _stk;
		for(int k = 0 ; k < stk.size() ; k++){
			string _str = stk[k];
			for(int j = i ; j < end ; j++){
				swap(_str[j],_str[end-1]);
				_stk.push_back(_str);
				swap(_str[j],_str[end-1]);
			}
		}
		stk = _stk;
	}
	for(int i = 0 ; i < stk.size() ; i++){
		cout<<"��"<<count++<<"��: "<<stk[i]<<'\n';
	}
}
int main(){
	string str = "abcd";
	_permutation_(str,0,str.length());
	return 0;
}
