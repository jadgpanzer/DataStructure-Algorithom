#include <iostream>

void queue(){
	int m , n;
	std::cin>>m>>n;
	char queue[20];
    int front = 0;
    int rear = 0;
    for(int i = 0 ; i< n ; i++){
    	int num ; 
		char element;
		std::cin>>num;
		if(num == 1){
			std::cin>>element;
			rear = (rear+1)%m ;
			queue[rear] = element;
		}
		else if(num == 2){
			front = (front+1)%m ;
		}
		std::cout<<front<<' '<<rear<<'\n';
	}
	if(front > rear){
		for(int i = front + 1; i < m ;i++ ){
			std::cout<<queue[i];
		}
		for(int i = 0 ; i <= rear ; i++ ){
			std::cout<<queue[i];
		}
	}
	else{
		if(front == rear){
			return ;
		}
		for(int i = front+1 ; i <= rear ;i++ ){
			std::cout<<queue[i];
		}
	}
	
	return ;
}
int main(){
	queue();
	return 0;
}
