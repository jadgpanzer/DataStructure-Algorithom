#include <iostream>
#include <string>
#include <vector>
using namespace std;
int count = 1;
/*全排列的实质是依次将第i位到最后一位之间的每个数进行交换，之后将第i+1位到最后一位之间的每个数进行交换*/
/*因此我们采用递归的方式进行*/
void permutation(string str,int start,int end){
	//str为要交换的序列，start为起点，初始为0，end为交换的终点，初始为字符串的长度 
	
	//最后无法交换了，函数返回，输出最终的排列结果 
	if(start == end-1){
		cout<<"第"<<count++<<"组："<<str<<'\n';
		return ;
	}
	else{
		//在本层将start到end之间的每个元素交换，然后在下一层将start+1到end之间的每个元素交换 
		for(int i = start ; i < end ; i++){
			swap(str[i],str[end-1]);
			permutation(str,start+1,end);
			swap(str[i],str[end-1]);
		}
	}
	return ;
}
/*非递归方法实现的全排列*/
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
		cout<<"第"<<count++<<"组: "<<stk[i]<<'\n';
	}
}
int main(){
	string str = "abcd";
	_permutation_(str,0,str.length());
	return 0;
}
