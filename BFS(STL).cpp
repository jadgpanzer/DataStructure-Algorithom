#include <iostream>
#include <queue>
#define MAX_SIZE 200
#define OPEN true
#define CLOSE false
using namespace std;
struct Point{
		bool visited;
		int x;
		int y;
		queue<Point*> path;
};
class BFS{
	public:
		Point grid[MAX_SIZE][MAX_SIZE];
		bool in_range(int x ,int y , int range_x,int range_y);
		void _bfs_(int length,int width,queue<Point*> old_list,Point* end);
};

bool BFS::in_range(int x ,int y , int range_x,int range_y){
	if(0 <= x && 0 <= y){
		if( x < range_x && y < range_y){
			return true;
		}
	}
	return false ;
}
void BFS::_bfs_(int length,int width,queue<Point*> old_list,Point* end){
	int dx[] = {0,0,1,-1};
	int dy[] = {1,-1,0,0};
	queue<Point*> new_list;
	for( ; !old_list.empty() ;){
		
		int x = old_list.front()->x ;
		int y = old_list.front()->y ;
		
		for(int  i = 0 ; i < 3 ; i++){
			
			if( in_range(x+dx[i],y+dy[i],length,width) ){
				
				if(grid[x+dx[i]][y+dy[i]].visited){
					
					queue<Point*> new_path =  old_list.front()->path;
					new_path.push(old_list.front());
					
					grid[x+dx[i]][y+dy[i]].path = new_path;
					grid[x+dx[i]][y+dy[i]].visited = CLOSE;
					
					if( &(grid[x+dx[i]][y+dy[i]]) == end){
						
						return ;
					}
					new_list.push( &(grid[x+dx[i]][y+dy[i]]) );
				}
				
			}
			
		}
		
		old_list.pop();
		
	}
	
	_bfs_(length,width,new_list,end);
	return ;
}
Point grid[MAX_SIZE][MAX_SIZE];
int main(){
	for(int i = 0 ; i < 7 ; i ++){
		for(int j = 0 ; j < 7 ; j++){
			grid[i][j].x = i ;
			grid[i][j].y = j ;
			grid[i][j].visited = OPEN;
		}
	}
	queue<Point*> list;
	list.push(&(grid[0][0]));
	grid[0][0].visited = CLOSE;
	BFS _bfs;
	_bfs.grid = grid;
	for( ; !grid[2][2].path.empty() ; ){
		cout<<grid[2][2].path.front()->x<<" "<<grid[2][2].path.front()->y<<'\n';
		grid[2][2].path.pop();
	}
}
