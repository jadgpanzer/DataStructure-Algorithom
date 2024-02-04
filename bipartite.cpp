#include <iostream>
using namespace std;
int colour[50]={0};
int G[50][50];

int main(){
	int num;
	cin>>num;
	int result[50];
	for(int i = 0 ; i < num ; i++){
		int size;
		cin>>size;
		for(int j = 0 ; j < size ; j++){
			colour[j] = 0 ;
		}
		for(int j = 0 ; j < size ; j++){
			for(int k = 0; k < size ; k++){
				cin>>G[j][k];
			}
		}
		colour[0] = 1;
		for(int j = 0 ; j < size ; j++){
			for(int k = 0; k < size ; k++){
				if(G[j][k] == 1){
					if(colour[j] == -1 && colour[k] == 0){
						colour[k] = 1 ;
					}
					if(colour[j] == 1 && colour[k] == 0){
						colour[k] = -1;
					}
					if(colour[k] == -1 && colour[j] == 0){
						colour[j] = 1 ;
					}
					if(colour[k] == 1 && colour[j] == 0){
						colour[j] = -1;
					}
				}
			}
		}
		int flag = 1 ;
		for(int j = 0 ; j < size ; j++){
			for(int k = 0; k < size ; k++){
				if(G[j][k] == 1){
					if(colour[j] + colour[k] != 0){
						flag = 0;
						break;
					}
				}
			}
		}
		result[i] = flag ;
	}
	for(int i = 0 ; i<num ;i++){
		if(result[i] == 0){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n";
		}
	}
}
