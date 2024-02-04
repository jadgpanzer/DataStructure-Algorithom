#include <cmath>
#include <stdio.h>
int length ;
int array[21];
int my_xor(int k , int p){
	if(k == p){
		return 0 ;
	}
	else{
		return 1;
	}
}
void add(int* number){
	number[20] ++ ;
	for(int i = 20 ; i >= 21-length ; i--){
		if(number[i]  == 2){
			number[i] = 0 ;
			number[i-1] ++ ; 
		}
	}
}
void make_gray(){
	int number[21] = {0};
	for(int i = 0 ; i < pow(2,length); i++){
		int p = number[21-length];
		printf("%d",number[21-length]);
		for(int j = 1 ; j < length ; j++){
			int k = number[21-length+j];
			int result = my_xor(k,p);
			printf("%d",result);
			p = k;
		}
		printf("\n");
		add(number);
	}
}
int main(){
	scanf("%d",&length);
	make_gray();
	return 0 ;
}
