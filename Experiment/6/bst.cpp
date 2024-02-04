#include <iostream>
struct Node{
	int num;
	Node* left = NULL;
	Node* right = NULL;
};
void makeNode(Node* p , int data){	
	if(p->num > data){
		if(p->left == NULL){
			p->left = new Node;
			p->left->num = data ;
			return ;
		}
		else{
			makeNode(p->left,data);
		}
	}
	else{
		if(p->right == NULL){
			p->right = new Node;
			p->right->num = data ;
			return ;
		}
		else{
			makeNode(p->right,data);
		}
	}
}
int data[1000];
int num  = 0 ;
void makeTree(Node& root){
	
	std::cin>>num;
	for(int i = 0 ; i <num ; i++){
		std::cin>>data[i] ;	
	}
	
	root.num = data[0] ;
	for(int i = 1 ; i <num ; i++){
		makeNode(&root,data[i]);	
	}
}
int layers[1000];
int degree[1000];
int count = 0 ;
void in_search(Node* p , int layer){
	if(p == NULL){
		return ;
	}
	in_search(p->left,layer+1);
	std::cout<<p->num<<' ';
	layers[count] = layer ;
	if(p->left != NULL){
		degree[count]++;
	}
	if(p->right != NULL){
		degree[count]++;
	}
	count ++ ;
	in_search(p->right,layer+1);
}
int main(){
	Node root ;
	makeTree(root);
	in_search(&root,1);
	std::cout<<'\n';
	for(int i = 0 ; i < num ; i++){
		std::cout<<layers[i]<<' ';
	}
	std::cout<<'\n';
	for(int i = 0 ; i < num ; i++){
		std::cout<<degree[i]<<' ';
	}
	std::cout<<'\n';
	return 0;
}
