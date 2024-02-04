#include <iostream>

using namespace std;

const int MAXN = 100; // ��󶥵���
int n = 0; // ������
int map[MAXN][MAXN] = {0}; // �ڽӾ���
int dfn[MAXN] = {0}, low[MAXN]= {0}, parent[MAXN]= {0}; // dfn, low��parent����
bool cut[MAXN]= {0}; // �Ƿ��ǹؽڵ�
int timestamp = 0; // ʱ���

// DFS����
void DFS(int cur) {
	++timestamp;
	low[cur] = timestamp ;
    dfn[cur] = low[cur] ;  // ����ʱ�����dfn��low����
    int child = 0;
    for (int i = 0; i < n; ++i) {
        if (map[cur][i] == 1) { // �������һ����cur��i�ı�
            if (dfn[i] == 0) { // ���iδ�����ʹ�
                child++;
                parent[i] = cur;
                DFS(i);
                low[cur] = min(low[cur], low[i]); // ����lowֵ
                if (parent[cur] == -1 && child > 1) { // ���cur�Ǹ��ڵ����������������ӽڵ�
                    cut[cur] = true; // ��cur�ǹؽڵ�
                }
                if (parent[cur] != -1 && low[i] >= dfn[cur]) { // ���i�ĺ��û��ָ��cur������
                    cut[cur] = true; // ��cur�ǹؽڵ�
                }
            }
            else if (i != parent[cur]) { // ���i�����ʹ����Ҳ���cur�ĸ��ڵ�
                low[cur] = min(low[cur], dfn[i]); // ����lowֵ
            }
        }
    }
}

// ���ҹؽڵ㺯��
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
