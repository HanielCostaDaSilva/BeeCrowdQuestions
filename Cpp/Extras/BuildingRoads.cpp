#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(string& preorder, string& inorder, int preStart, int preEnd, int inStart, int inEnd, unordered_map<char, int>& indexMap) {
    if (preStart > preEnd) return nullptr;

    char rootValue = preorder[preStart];
    TreeNode* root = new TreeNode(rootValue);

    int rootIndex = indexMap[rootValue];
    int leftSubtreeSize = rootIndex - inStart;

    root->left = buildTree(preorder, inorder, preStart + 1, preStart + leftSubtreeSize, inStart, rootIndex - 1, indexMap);
    root->right = buildTree(preorder, inorder, preStart + leftSubtreeSize + 1, preEnd, rootIndex + 1, inEnd, indexMap);

    return root;
}

TreeNode* buildTree(string& preorder, string& inorder) {
    unordered_map<char, int> indexMap;
    for (int i = 0; i < inorder.size(); ++i) {
        indexMap[inorder[i]] = i;
    }

    return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1, indexMap);
}

void postorderTraversal(TreeNode* root) {
    if (root == nullptr) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->val;
}

int main() {
    string preorder, inorder;
    while (cin >> preorder >> inorder) {
        TreeNode* root = buildTree(preorder, inorder);
        postorderTraversal(root);
        cout << endl;
    }
    return 0;
}
