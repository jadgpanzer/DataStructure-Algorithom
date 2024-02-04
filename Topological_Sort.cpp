#include <iostream>
#define MAX_SIZE 500
#define MAX_DIST 0x00FFFFFF
class Stack{
	public:
		void push(int val);
		void pop();
		bool is_empty();
		int get_top();
		int get_size();
		int top;
		int size ;
		int stack[MAX_SIZE];
		Stack();
};
Stack::Stack(){
	top = - 1;
}
void Stack::pop(){
	if(!is_empty()){
		top -- ;
	}
}
void Stack::push(int val){
	top ++ ;
	stack[top] = val ; 
}
bool Stack::is_empty(){
	if(top == -1){
		return true ;
	}
	else{
		return false ;
	}
}
int Stack::get_top(){
	if(!is_empty()){
		return stack[top];
	}
	else{
		return -1;
	}
}
int indegree[MAX_SIZE] = {0}; 
int matrix[MAX_SIZE][MAX_SIZE] = {0};
int size;
Stack my_stack ;
int sort_result[MAX_SIZE];
void add(){
	for(int i = 0 ; i < size ; i++){
		if(indegree[i] == 0){
			my_stack.push(i);
			indegree[i] = - 1;
		}
	}
}
void topological_sort(){
	add();
	for(int i = 0 ; i < size ; i++){
		add();
		int temp = my_stack.get_top();
		my_stack.pop();
		sort_result[i] = temp ;
		for(int j = 0 ; j < size ; j++){
			if(matrix[i][j]!=MAX_DIST && indegree[j] != -1){
				indegree[j] -- ;
			}
		}
	}
	for(int i = 0 ; i < size ; i++){
		std::cout<<sort_result[i]<<' ';
	}
}
/*
0 1 0 0 1
0 0 1 1 0
0 0 0 0 1
0 0 0 0 1
0 0 0 0 0
*/
int main(){
	std::cin>>size ;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j ++){
			std::cin>>matrix[i][j];
			if(matrix[i][j] == 0){
				matrix[i][j] = MAX_DIST ;
			}
			else{
				indegree[j]++;
			}
		}
	}
	topological_sort();
	return 0 ;
}

