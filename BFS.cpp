#include <iostream>
using namespace std;

const int MAX_SIZE = 100; 
int G[MAX_SIZE][MAX_SIZE]; 
bool visited[MAX_SIZE]; 

class Queue {
private:
    int data[MAX_SIZE]; 
    int frontIndex; 
    int rearIndex; 
public:
    Queue() { 
        frontIndex = 0;
        rearIndex = 0;
    }

    void push(int x) { 
        if (rearIndex >= MAX_SIZE) {
            cout << "Queue is full." << endl;
            return;
        }
        data[rearIndex++] = x;
    }

    void pop() { 
        if (frontIndex == rearIndex) {
            cout << "Queue is empty." << endl;
            return;
        }
        frontIndex++;
    }

    int front() {
        if (frontIndex == rearIndex) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return data[frontIndex];
    }

    bool empty() {
        return frontIndex == rearIndex;
    }
};
void bfs(int start, int n) {
    Queue q; 
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        cout << cur << " "; 

        for (int i = 0; i < n; i++) {
            if (G[cur][i] && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

int main() {
    int n;
    cin >> n;
    //邻接矩阵项为0代表两点之间没有连接 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> G[i][j];
        }
    }
    bfs(0, n);

    return 0;
}
