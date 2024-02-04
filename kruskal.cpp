#include <iostream>
#define MAX_SIZE 500
#define MAX_DIST 0x00FFFFFF
int size = 0 ;
int matrix[MAX_SIZE][MAX_SIZE] = {0};
bool is_open[MAX_SIZE][MAX_SIZE]={false} ;
int group[MAX_SIZE];

void search(){
	for(int i = 0 ; i < size ; i++){
		group[i] = i ;
	}
	for(int k = 0 ; k < size - 1; k ++){
		int tx = -1, ty = -1,temp;
		for(int i = 0 ; i < size ; i++){
			for(int j = i ; j < size ; j++){
				if(matrix[MAX_SIZE][MAX_SIZE] == MAX_DIST){
					continue ;
				}
				if(tx + ty == -2 && group[i] != group[j]){
					tx = i ;
					ty = j ;
					temp = matrix[i][j] ;
					continue ;
				}
				if(group[i] != group[j] && matrix[i][j] < temp && is_open[i][j] == false){
					temp = matrix[i][j] ;
					tx = i ;
					ty = j ;
				}
			}
		}
		int mi = std::min(tx,ty);
		int bi = std::max(tx,ty);
		for(int i = 0 ; i < size ; i ++){
			if(group[i] == bi){
				group[i] = mi ;	
			}
		}
		is_open[tx][ty] = true ;	
	}
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(is_open[i][j] == true){
				std::cout<<" ("<<i<<','<<j<<") ";
			}
		}
	}
}
int main(){
	std::cin>>size ;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j ++){
			std::cin>>matrix[i][j];
			if(matrix[i][j] == 0){
				matrix[i][j] = MAX_DIST ;
			}
		}
	}
	search();
	return 0 ;
}
