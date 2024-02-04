#include <iostream>
#define MAXSIZE 10000
struct Node{
	Node* left = NULL;
	Node* right = NULL;
	int value = 1000000;
};
void swap(int& a ,int& b){
	int temp = a ;
	a = b ;
	b = temp ;
}
class Heap{
	Node heap[MAXSIZE];
	int count ;
	public:	
		Heap(){
			count = 0 ;
			heap[0].value = - 1;
		}
		void Insert(int val){
			count ++ ;
			heap[count].value = val ;
			if(count == 1){
				return ;
			}
			upwards_adjust(count) ;
		}
		void upwards_adjust(int pos){
			if(heap[pos].value < heap[pos/2].value){
				swap(heap[pos].value,heap[pos/2].value);
				upwards_adjust(pos/2);
			}
		}
		int Delete_Min(){
			int temp = heap[1].value ;
			heap[1].value = heap[count].value ;
			heap[count].value = 1000000;
			count -- ;
			downwards_adjust(1);
			return temp;
		}
		void downwards_adjust(int pos){
			if(heap[pos*2].value < heap[pos].value && heap[pos].value < heap[2*pos+1].value){
				swap(heap[2*pos].value , heap[pos].value);
				downwards_adjust(2*pos);
				return ;
			}
			if(heap[2*pos+1].value < heap[pos].value && heap[pos].value < heap[2*pos].value){
				swap(heap[2*pos+1].value , heap[pos].value);
				downwards_adjust(2*pos+1);
				return ;
			}
			if(heap[pos].value > heap[2*pos+1].value && heap[pos].value > heap[2*pos].value){
				if(heap[2*pos+1].value > heap[2*pos].value){
					swap(heap[2*pos].value,heap[pos].value);
					downwards_adjust(2*pos);
				}
				else{
					swap(heap[2*pos+1].value,heap[pos].value);
					downwards_adjust(2*pos+1);
				}
			}
		}
		void Delete(int i){
			heap[i].value = heap[count].value ;
			heap[count].value = 1000000;
			count -- ;
			downwards_adjust(i);
		}
		void Decrease_Value(int i, int val){
			heap[i].value = val ;
			upwards_adjust(i);
		}
		void output(){
			int temp = count ;
			for(int i = 1 ; i <= temp ; i++){
				std::cout<<Delete_Min()<<' ';
			}
		}
}; 
int main(){
	int num = 0 ;
	std::cin>>num ;
	Heap my_heap ;
	
	for(int i = 0 ; i < num;i ++){
		int num1  ,num2 ,num3;
		std::cin>>num1 ;
		if(num1 == 1){
			std::cin>>num2 ;
			my_heap.Insert(num2);
			
		}
		if(num1 == 2){
			my_heap.Delete_Min();
			
		}
		if(num1 == 3){
			std::cin>>num2 ;
			my_heap.Delete(num2);
			
		}
		if(num1 == 4){
			std::cin>>num2>>num3;
			my_heap.Decrease_Value(num2,num3);	
		}
	}
	my_heap.output();
}
