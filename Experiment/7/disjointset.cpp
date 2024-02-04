#include <iostream>
using namespace std;
const int N = 3000000;
int n, m;
int fa[N], size[N];
int find(int x) {
	if (x != fa[x])
		fa[x] = find(fa[x]);
	return fa[x];
}
void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) 
		return;
	if (size[fx] > size[fy])
		swap(fx, fy);
	fa[fx] = fy;
	size[fy] += size[fx];
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
		size[i] = 1;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) 
	    if (fa[i] == i)
			ans++;
	cout << ans << endl;
	return 0;
}
