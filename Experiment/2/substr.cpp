#include <iostream>
#define MAXNUM 20000
	
char str[MAXNUM] ;
char sub_str[MAXNUM] ;
int main(){
	int num = 0;
	int pos = 0;
	int len = 0;
	std::cin>>pos>>len;
	std::cin>>str;
	for(int i = 0 ;  i < len && str[i+pos-1]!='\0' ; i++ ,num ++){
		sub_str[num] = str[i+pos-1];
	}
	std::cout<<sub_str;
	return 0;
} 
