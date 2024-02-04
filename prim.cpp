#include <iostream>
#define MAX 500
#define MAX_DIST 0x00FFFFFF
int matrix[MAX][MAX];
bool v_visited[MAX] = {false};
bool edge_visited[MAX][MAX] = {false};
int size ;
void get_min(){
	int temp_x = -1, temp_y = -1 ,temp ;
	for(int i = 0 ; i < size ; i ++ ){
		for(int j = i ; j < size ; j++){
			if( v_visited[i]^v_visited[j] == 0 || matrix[i][j] == MAX_DIST || edge_visited[i][j] == true){
				continue ;
			}
			if(temp_x+temp_y == -2||matrix[i][j] < temp){
				temp_x = i ;
				temp_y = j;
				temp = matrix[i][j];
			}
		}
	}
	edge_visited[temp_x][temp_y] = true ;
	v_visited[temp_x] = true;
	v_visited[temp_y] = true;
}
void prim(){
	v_visited[0] = true ;
	for(int i = 0 ; i <size -1 ; i++){
		get_min();
	}
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(edge_visited[i][j] == true){
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
	prim() ;
	return 0 ;
}

