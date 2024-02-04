#include<stdio.h>
#include<malloc.h>

struct node{
    int data;
    node *next;
};

node *createLinkList(int n) {  // Î²²åÈë·¨ 
    node *head, *tail, *p;
    head = tail = (node*) malloc(sizeof(node));
    tail->next = NULL;
    for (int i = 0; i < n; ++ i) {
        int x;
        scanf("%d", &x);
        p = (node*) malloc(sizeof(node));
        p->data = x; p->next = NULL;
        tail->next = p; tail = p;
    }
    return head;
}

void LinkList_Print(node *A) {
    node *p = A->next;
    while (p != NULL) {
        printf("%d ", p->data); p = p->next;
    }
}

node *combineLinkList(node *A, node *B) {
    node *head, *tail, *p;
    head = tail = (node*)malloc(sizeof(node));
    tail->next = NULL;
    node* start = B->next;
    A = A->next; B = B->next;
    for(  ;A != NULL &&B!=NULL ;  ){
    	
		if(A->data == B->data){
			tail->next = B;
        	tail = tail->next;
        	A = A->next; 
			B = start;
		}
		else{
			B = B->next;
		}
		if(B == NULL){
			A = A->next; 
			B = start;
		}
	}
    tail->next = NULL;
    return head;
}

int main() {
    int m, n;
    scanf("%d%d", &m, &n);
    node *A = createLinkList(m);
    node *B = createLinkList(n);
    node *C = combineLinkList(A, B);
    LinkList_Print(C);
	return 0;
}

