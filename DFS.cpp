#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 

int G[MAX_SIZE][MAX_SIZE]; 
bool visited[MAX_SIZE]; 

void dfs(int cur, int n) {
    visited[cur] = true;
    cout << cur << " "; 

    for (int i = 0; i < n; i++) {
        if (G[cur][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n; 
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    dfs(0, n);
    return 0;
}
