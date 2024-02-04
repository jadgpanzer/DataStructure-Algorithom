#include <iostream>
using namespace std;
struct Node{
	Node* left = NULL;
	Node* right = NULL ;
	int data = -1;
};
int number ;
int in_search[10002];
int back_search[10002];
int pos ;
int search(int target){
	for(int i = 0 ; i < number ; i++){
		if(in_search[i] == target){
			return i ;
		}
	}
	return -1 ;
}
void make_tree(Node* parent,int start,int end){
	if(pos < 0){
		return ;
	}
	if(start > end){
		return ;
	}
	
	Node* root = new Node;
	if(parent->right == NULL){
		parent->right = root ;
	}
	else{
		parent->left = root ;
	}
	root->data = back_search[pos];
	int root_pos = search(back_search[pos]);
	pos -- ;
	
	make_tree(root,root_pos+1,end);
	make_tree(root,start,root_pos-1);
}
/*
6
2 1 6 3 4 5 
2 6 3 5 4 1
*/
void forward_search(Node* root){
	if(root == NULL){
		return ;
	}
	cout<<root->data<<' ';
	forward_search(root->left);
	forward_search(root->right);
}
int main(){
	cin>>number;
	pos = number - 1 ;
	for(int i = 0 ; i < number ; i++){
		cin>>in_search[i];
	}
	for(int i = 0 ; i < number ; i++){
		cin>>back_search[i];
	}
	Node *root = new Node;
	root->data = back_search[pos];
	int root_pos = search(back_search[pos]);
	pos -- ;
	
	make_tree(root,root_pos+1,number-1);
	make_tree(root,0,root_pos-1);
	forward_search(root);
	return 0 ;
}
