#include <iostream>
using namespace std;
struct Node{
	Node* left;
	Node* right;
	int data;
};
struct Tree{
	Node _nodes[100];
	Node* root;
};
class Stack{
	private:
		int top;
		Node* container[100];
	public:
		Stack(){
			top = -1;
		}
		void push(Node* _node){
			top ++ ;
			container[top] = _node;
		}
		void pop(){
			if(isEmpty()){
				cout<<"Stack is Empty!";
				system("pause");
			}
			top -- ;
		}
		Node* getTop(){
			if(isEmpty()){
				cout<<"Stack is Empty!";
				system("pause");
				return NULL;
			}
			return container[top];
		}
		bool isEmpty(){
			if(top == -1){
				return true;
			}
			else{
				return false;
			}
		}
};
void init(Tree& _tree){
	int i = 0;
	while(i < 10){
		_tree._nodes[i].data = i;
		_tree._nodes[i].left = NULL;
		_tree._nodes[i].right = NULL;
		i ++ ;
	}
	_tree.root = _tree._nodes;
	_tree._nodes[0].left = _tree._nodes + 1 ;
	_tree._nodes[0].right = _tree._nodes + 2 ;
	_tree._nodes[1].left = _tree._nodes + 3 ;
	_tree._nodes[1].right = _tree._nodes + 4 ;
	_tree._nodes[3].left = _tree._nodes + 7 ;
	_tree._nodes[3].right = _tree._nodes + 8 ;
	_tree._nodes[4].right = _tree._nodes + 9 ;
	_tree._nodes[2].left = _tree._nodes + 5 ;
	_tree._nodes[2].right = _tree._nodes + 6 ;
}
void search(Tree& _tree){
	Stack stk;
	stk.push(_tree.root);
	Node* p = _tree.root;
	while(!stk.isEmpty()){
		if(p != NULL){
			stk.push(p);
			p = p->left;	
		}
		else{
			Node* temp = stk.getTop();
			stk.pop();
			cout<<temp->data<<' ';
			p = temp->right;
		}
	}
}
int main(){
	Tree my_tree;

	init(my_tree);
	
	search(my_tree);
	return 0;
}
