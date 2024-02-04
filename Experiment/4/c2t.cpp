#include <iostream>
using namespace std;

struct Node {
	char data = 0;
	int parent;
	int lchild, rchild;
} nodes[101];
int n, lastchild[101];

void buildTree() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> nodes[i].data >> nodes[i].parent;
	for (int i = 2; i <= n; i++) {
		int f = nodes[i].parent;
		if (lastchild[f] == 0)
			nodes[f].lchild = lastchild[f] = i;
		else {
			// Insert your code here
			nodes[lastchild[f]].rchild = i;
			lastchild[f] = i;
		}
	}
}


void Preorder(Node &root) {
	// Insert your code here
	if (root.data == 0) return;
	cout << root.data ;
	Preorder(nodes[root.lchild]);
	Preorder(nodes[root.rchild]);

}
void Midorder(Node &root) {
	// Insert your code here
	if (root.data == 0) return;

	Midorder(nodes[root.lchild]);
	cout << root.data ;
	Midorder(nodes[root.rchild]);
}
void Postorder(Node &root) {
	// Insert your code here
	if (root.data == 0) return;

	Postorder(nodes[root.lchild]);

	Postorder(nodes[root.rchild]);
	cout << root.data ;
}


int main() {
	buildTree();
	Preorder(nodes[1]);
	cout << "\n";
	Midorder(nodes[1]);
	cout << "\n";
	Postorder(nodes[1]);
	return 0;
}
