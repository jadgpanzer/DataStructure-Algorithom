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
	/*�ݹ�Ļ���ԭ���ڷ�����һ��֮ǰ����Ҫ��ջ����ԭ����Ҳ���ǵ�ջ֮��Ҫ��ջ����ջ֮��Ҫ��ջ��������ִ�еݹ麯��֮��
	�����ص���һ���ʱ��ջ��û�з����仯�ģ����ݣ�*/
	if(pos == _stack->size && _stack->is_empty()){	//������Ԫ�ض���ջ֮�� ���������أ���ӡ��ջ��� ���ݹ�����²㣩 
		for(int i = 0 ; i < list.size() ;i++){
			cout<<list[i]<<' ';
		}
		cout<<'\n';
		return ;
	}
	else{
		if(_stack->is_empty()){						//ջ��ֻ����ջ 
			_stack->push(element[pos]);
			recurrent(_stack,element,pos+1,list);
			_stack->pop();//��ԭ 
			return ;
		}
		if(_stack->is_full()){						// ջ��ֻ�ܳ�ջ 
			int temp = _stack->pop();
			list.push_back(temp);
			recurrent(_stack,element,pos,list);
			_stack->push(temp);//��ԭ 
			return ;
		}
		if(!_stack->is_empty()&&!_stack->is_full()&&pos<_stack->size){
																	    //��û��ջ��Ҳû��ջ�գ����һ����Լ�������Ԫ�ص�ʱ�������Ƚ�����ջ�� 
			_stack->push(element[pos]);									//��ԭ֮����е�ջ�������ں������ݵ���һ���ʱ��Ϳ�������һ����֧ 
			recurrent(_stack,element,pos+1,list);
			_stack->pop();
		
			int temp = _stack->pop();
			list.push_back(temp);
			recurrent(_stack,element,pos,list);
			_stack->push(temp);
			return ;
		}
		if(pos==_stack->size){											// ȫ�� Ԫ�ض���ջ�ˣ�ֻ�ܳ�ջ 
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
