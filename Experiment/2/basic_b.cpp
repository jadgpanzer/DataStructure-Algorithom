#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int m; //命令数

struct node{
int data;
struct node *next;
};
node *head; // head指向头节点
int size = 0 ;

void insert(int i, int x){//插入x到a[i]
	node* start = head ;
	for(int j = 1 ; j < i ; j++){
		start = start -> next ;
	}
	node* newNode = new node ;
	newNode -> data = x ;
	newNode -> next = start -> next ;
	start -> next = newNode ;
	size ++ ;
}

void deleteByIndex(int i){ //删除a[i]
	node* start = head ;
	for(int j = 1 ; j < i ; j++){
		start = start -> next ;
	}
	node* temp = start -> next ;
	start -> next = temp -> next ;
	free(temp) ;
	size -- ;
}

void find(int x){//查找第一个x
	node* start = head -> next ;
	int i = 1 ;
	while(start != NULL){
		if(start -> data == x){
			printf("%d\n", i) ;
			return ;
		}
		start = start -> next ;
		i ++ ;
	}
	printf("0\n") ;
}

void eliminateRepeat(){ //去除重复元素
	node* p = head -> next ;
	while(p != NULL && p -> next != NULL){
		node* q = p ;
		while(q -> next != NULL){
			if(q -> next -> data == p -> data){
				node* temp = q -> next ;
				q -> next = q -> next -> next ;
				free(temp) ;
				size -- ;
			}
			else{
				q = q -> next ;
			}
		}
		p = p -> next ;
	}
}

void count(int x, int y){//统计[x,y]中元素个数
	int k = 0;
	node *p = head->next;
	while (p != NULL){
		if (p->data >= x && p->data <= y){
			k++;
		}
		p = p->next;
	}
	printf("%d\n", k);
}

void deleteByRange(int x, int y){ //去除[x,y]范围内的元素
	node *p = head;
	node *q = head-> next;
	while (q != NULL){
		if (q->data >= x && q->data <= y){
			p->next = q->next; free(q); q = p->next;
			size -- ;
		}
		else{
			p = q; q = p->next;
		}
	}
}

int main() {
	scanf("%d", &m);
	head = (node*) malloc(sizeof(node));
	head->next = NULL;
	for (int k = 0; k < m; k++){
		int c, i, x, y;
		scanf("%d", &c);
		switch (c){
			case 1: scanf("%d%d", &i, &x); insert(i, x); break;
			case 2: scanf("%d", &i); deleteByIndex(i); break;
			case 3: scanf("%d", &x); find(x); break;
			case 4: scanf("%d%d", &x, &y); count(x, y); break;
			case 5: eliminateRepeat(); break;
			case 6: scanf("%d%d", &x, &y); deleteByRange(x, y); break;
		}
	}
	return 0;
}

