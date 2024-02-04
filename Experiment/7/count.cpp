#include <iostream>
#include <string>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(string& s, int& index) {
    if (index >= s.size() || s[index] == '#') {
        return nullptr;
    }
    TreeNode* root = new TreeNode(s[index] - '0');
    index++;
    root->left = buildTree(s, index);
    index++;
    root->right = buildTree(s, index);
    return root;
}
int countSingleChildNodes(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 0;
    }
    int cnt = 0;
    if (root->left && !root->right) {
        cnt++;
    }
    if (root->right && !root->left) {
        cnt++;
    }
    return cnt + countSingleChildNodes(root->left) + countSingleChildNodes(root->right);
}

int main() {
    string s;   
    cin >> s;
    int index = 0;
    TreeNode* root = buildTree(s, index);
    int ans = countSingleChildNodes(root);
    cout << ans << endl;
    return 0;
}
