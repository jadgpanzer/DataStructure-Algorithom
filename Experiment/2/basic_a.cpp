#include <iostream>
#define maxn 10000
using namespace std;

int m;
int n = 0;
int arr[maxn];

void insert(int i, int x) {
	for (int j = n - 1; j >= i; j--) {
		arr[j + 1] = arr[j];
	}
	arr[i] = x;
	n++;
}

void deleteByIndex(int i) {
	for (int j = i; j < n; j++) {
		arr[j] = arr[j + 1];
	}
	n--;
}

void find(int x) {
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) {
			cout << i + 1 << endl;
			return;
		}
	}
	cout << 0 << endl;
}
void count(int x, int y) {
	int t = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= x && arr[i] <= y)
			t++;
	}
	cout << t << endl;
}
void eliminateRepeat() {
	int i = 0;
	while (i < n) {
		int k = i + 1;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] != arr[i])
				arr[k++] = arr[j];
		}
		n = k;
		i++;
	}
}
void deleteByRange(int x, int y) {
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] < x || arr[i] > y)
			arr[k++] = arr[i];
	}
	n = k;
}
void show() {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}
int main() {
	scanf("%d", &m);
	for (int k = 0; k < m; k++) {
		int c, i, x, y;
		scanf("%d", &c);
		switch (c) {
			case 1:
				scanf("%d%d", &i, &x);
				insert(i - 1, x);
				break;
			case 2:
				scanf("%d", &i);
				deleteByIndex(i - 1);
				break;
			case 3:
				scanf("%d", &x);
				find(x);
				break;
			case 4:
				scanf("%d%d", &x, &y);
				count(x, y);
				break;
			case 5:
				eliminateRepeat();
				break;
			case 6:
				scanf("%d%d", &x, &y);
				deleteByRange(x, y);
				break;
			case 7:
				show();
				break;
		}
	}
	return 0;
}


