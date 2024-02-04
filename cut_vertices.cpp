#include <iostream>

using namespace std;

const int MAXN = 100; // 最大顶点数
int n = 0; // 顶点数
int map[MAXN][MAXN] = {0}; // 邻接矩阵
int dfn[MAXN] = {0}, low[MAXN]= {0}, parent[MAXN]= {0}; // dfn, low和parent数组
bool cut[MAXN]= {0}; // 是否是关节点
int timestamp = 0; // 时间戳

// DFS函数
void DFS(int cur) {
	++timestamp;
	low[cur] = timestamp ;
    dfn[cur] = low[cur] ;  // 更新时间戳和dfn、low数组
    int child = 0;
    for (int i = 0; i < n; ++i) {
        if (map[cur][i] == 1) { // 如果存在一条从cur到i的边
            if (dfn[i] == 0) { // 如果i未被访问过
                child++;
                parent[i] = cur;
                DFS(i);
                low[cur] = min(low[cur], low[i]); // 更新low值
                if (parent[cur] == -1 && child > 1) { // 如果cur是根节点且有两个或以上子节点
                    cut[cur] = true; // 则cur是关节点
                }
                if (parent[cur] != -1 && low[i] >= dfn[cur]) { // 如果i的后代没有指向cur的祖先
                    cut[cur] = true; // 则cur是关节点
                }
            }
            else if (i != parent[cur]) { // 如果i被访问过，且不是cur的父节点
                low[cur] = min(low[cur], dfn[i]); // 更新low值
            }
        }
    }
}

// 查找关节点函数
void Find_Cut_Vertex() {
    timestamp = 0;
    for (int i = 0; i < n; ++i) {
        if (dfn[i] == 0) {
            DFS(i);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (cut[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
    Find_Cut_Vertex();

    return 0;
}
