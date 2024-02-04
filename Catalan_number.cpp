#include <iostream>
#include <vector>
using namespace std;
class stack{
	public:
		int* number;
		int top;
		int size;
		stack(int _size);
		int pop();
		int push(int _x);	
		bool is_empty();	
		bool is_full();
};
stack::stack(int _size){
	this->top = 0;
	this->size = _size;
	this->number = new int[_size+1];
}
int stack::push(int _x){
	top ++;
	number[top] = _x;
	return _x;
}
int stack::pop(){
	if(is_empty()){
		std::system("exit");
	}
	else{
		int temp = this->number[top];
		top--;
		return temp;
	}
}
bool stack::is_empty(){
	if(this->top == 0){
		return true;
	}
	else{
		return false;
	}
}
bool stack::is_full(){
	if(this->top == this->size){
		return true;
	}
	else{
		return false;
	}
}
void recurrent(stack* _stack,int* element,int pos,vector<int>list){
	/*递归的基本原则：在返回上一层之前，需要将栈“复原”，也就是弹栈之后要入栈，入栈之后要弹栈，这样在执行递归函数之后
	，返回到上一层的时候，栈是没有发生变化的（回溯）*/
	if(pos == _stack->size && _stack->is_empty()){	//当所有元素都弹栈之后 ，函数返回，打印出栈结果 （递归的最下层） 
		for(int i = 0 ; i < list.size() ;i++){
			cout<<list[i]<<' ';
		}
		cout<<'\n';
		return ;
	}
	else{
		if(_stack->is_empty()){						//栈空只能入栈 
			_stack->push(element[pos]);
			recurrent(_stack,element,pos+1,list);
			_stack->pop();//复原 
			return ;
		}
		if(_stack->is_full()){						// 栈满只能出栈 
			int temp = _stack->pop();
			list.push_back(temp);
			recurrent(_stack,element,pos,list);
			_stack->push(temp);//复原 
			return ;
		}
		if(!_stack->is_empty()&&!_stack->is_full()&&pos<_stack->size){
																	    //既没有栈满也没有栈空，并且还可以继续加入元素的时候，我们先进行入栈， 
			_stack->push(element[pos]);									//复原之后进行弹栈，这样在函数回溯到这一层的时候就可以制造一个分支 
			recurrent(_stack,element,pos+1,list);
			_stack->pop();
		
			int temp = _stack->pop();
			list.push_back(temp);
			recurrent(_stack,element,pos,list);
			_stack->push(temp);
			return ;
		}
		if(pos==_stack->size){											// 全部 元素都入栈了，只能出栈 
			int temp = _stack->pop();
			list.push_back(temp);
			recurrent(_stack,element,pos,list);
			_stack->push(temp);
			return ;
		}
	}
}
int main(){
	stack stk(3);
	vector<int>list;
	int element[3] = {1,2,3};
	recurrent(&stk,element,0,list);
	return 0;
}
