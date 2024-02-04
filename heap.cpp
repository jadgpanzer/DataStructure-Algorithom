#include <iostream>
int heap[100];
int number = 0;
void Insert(int val){
	number ++ ;
	heap[number] = val ;
	int i = number ;
	while(i>1&&val<heap[i/2]){
		heap[i] = heap[i/2];
		i = i / 2;
	}
	heap[i] = val ;
}
int Delete_Min(){
	int i = 1,ch = 2*i ;
	int ret = heap[1] ;
	int val = heap[1] = heap[number];
	number -- ;
	while(i<=number){
		if(ch+1<=number&&heap[ch+1]<heap[ch]){
			ch = ch + 1;
		}
		if(heap[ch] > heap[i]){
			break ;
		}
		heap[i] = heap[ch];
		i = ch ;
		ch = ch*2;
	}
	heap[i] = val;
	return ret;
}
void Decrease_Value(int pos ,int val){
	heap[pos] = val;
	int i = pos ;
	while(i>1&&val<heap[i/2]){
		heap[i] = heap[i/2];
		i = i / 2;
	}
	heap[i] = val ;
}
int Delete(int pos){
	int ret = heap[pos];
	heap[pos] = heap[number];
	int val = heap[pos];
	number -- ;
	if(heap[pos] < ret){
		int i = pos ;
		while(i>1&&val<heap[i/2]){
			heap[i] = heap[i/2];
			i = i / 2;
		}
		heap[i] = val ;
	}
	else{
		int i = pos,ch = 2*i ;
		while(i<=number){
			if(ch+1<=number&&heap[ch+1]<heap[ch]){
				ch = ch + 1;
			}
			if(heap[ch] > heap[i]){
				break ;
			}
			heap[i] = heap[ch];
			i = ch ;
			ch = ch*2;
		}
		heap[i]=val;
	}
}
int output(){
	while(number != 0){
		std::cout<<Delete_Min()<<' ';
	}
}
int main(){
	int num = 0 ;
	std::cin>>num ;
	for(int i = 0 ; i < num;i ++){
		int num1  ,num2 ,num3;
		std::cin>>num1 ;
		if(num1 == 1){
			std::cin>>num2 ;
			Insert(num2);
			
		}
		if(num1 == 2){
			Delete_Min();
		}
		if(num1 == 3){
			std::cin>>num2 ;
			Delete(num2);
		}
		if(num1 == 4){
			std::cin>>num2>>num3;
			Decrease_Value(num2,num3);	
		}
	}
	output();
}
