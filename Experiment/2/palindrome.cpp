#include <iostream>
#define MAXNUM 1000000
char str[MAXNUM]={'\0'};
int main(){
	int pos1=0;
	int pos2=0;
	std::cin>>str;
	int i ;
	for(i = 0 ; str[i]!='@';i++){
		if(str[i]=='&'){
			pos1 = i ;
		}
	}
	pos2 = i -1;
	int flag = 0;
	for(int j = 0 ; j < pos1 ; j ++){
		if(str[pos2-j] != str[j]){
			flag = 1;
			std::cout<<0;
			break;
		}
	}
	if(flag == 0){
		std::cout<<1;
	}
	return 0;
} 
