#include <iostream>
using namespace std;
int array[100]={0};
int sub_str[100]={0};
int main(){
	int number = 0 ;
	cin>>number;
	for(int i = 0 ; i < number ; i++){
		cin>>array[i];
	}
	sub_str[0] = 1 ;	
	for(int i = 0 ; i < number; i++){
		int temp , pos = -1 ;
		for(int j = 0 ; j < i; j++){
			if(array[j] < array[i]){
				if(sub_str[j] > temp || pos == -1){
					temp = sub_str[j];
					pos = j;
				}
			}
		}
		if(pos == - 1){
			sub_str[i] = 1 ;	
		}
		else{
			sub_str[i] = sub_str[pos] + 1 ;
		}
	}
	for(int i = 0 ; i < number ; i++){
		cout<<sub_str[i]<<' ';
	}
	return 0;
}
