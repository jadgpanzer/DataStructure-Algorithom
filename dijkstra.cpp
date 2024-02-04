#include <iostream>
#define MAX 100
#define MAX_DIST 0x00FFFFFF
int matrix[MAX][MAX] ;
int dist[MAX];
int close_dist[MAX] ;
int size ;
int start ;
int get_min(){
	int index = -1;
	for(int i = 0 ; i < size ; i++){
		if(close_dist[i] == -1 || close_dist[i] == MAX_DIST){
			continue ;
		}
		else{
			if(index == -1 || close_dist[i] < close_dist[index]){
				index = i ;
			}
		}
	}
	return index ;
}
void dijk(){
	for(int i = 0 ; i < size ; i++){
		dist[i] = MAX_DIST ;
		close_dist[i] = MAX_DIST ;
	}
	dist[start] = 0 ;
	close_dist[start] = 0 ;
	for(int i = 0 ; i < size ; i ++){
		int min_point = get_min() ;
		dist[min_point] = close_dist[min_point];
		close_dist[min_point] = - 1 ;
		for(int j = 0 ; j < size ; j ++){
			if(close_dist[j] != -1  && dist[min_point] + matrix[min_point][j] < close_dist[j]){
				close_dist[j] = dist[min_point] + matrix[min_point][j] ;
			}
		}
	}
	for(int i = 0 ; i < size ; i ++){
		std::cout<<dist[i]<<' ';
	}
}
int main(){
	std::cin>>size ;
	std::cin>>start ;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j ++){
			std::cin>>matrix[i][j];
			if(matrix[i][j] == 0){
				matrix[i][j] = MAX_DIST ;
			}
		}
	}
	dijk();
	return 0 ;
}
