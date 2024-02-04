#include <iostream>
char array[] = {'A','B','C','D','E','F','G','H'};
char arr[8];
int find_pos(char target){
	int i = 0 ;
	while( i < 8){
		if(array[i] == target){
			return i;
		}
		i ++ ;
	}
}
void filo(){
	std::cin>>arr;
	int i , j = 0 ;
	int top = -1;
	char stack[8];
	while(i<8){
		stack[++top] = array[i++];
		for( ; top>=0 && stack[top] == arr[j] ;){
			top -- ;
			j++;
		}
	}
	if(j == 8){
		std::cout<<1;
	}
	else{
		std::cout<<0;
	}
}
int main(){
	filo();
	return 0;
}
