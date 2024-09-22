#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &preIndex, int inStart, int inEnd)
{
    if (inEnd < inStart)
        return nullptr;

    int val = preorder[preIndex++];
    int inMid = find(inorder.begin(), inorder.end(), val) - inorder.begin();

    TreeNode *root = new TreeNode(val);

    root->left = build(preorder, inorder, preIndex, inStart, inMid - 1);
    root->right = build(preorder, inorder, preIndex, inMid + 1, inEnd);

    return root;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIndex = 0;
    return build(preorder, inorder, preIndex, 0, inorder.size() - 1);
}

// Function to print the tree (inorder traversal)
void printInOrder(TreeNode *root)
{
    if (!root)
        return;
    printInOrder(root->left);
    cout << root->val << " ";
    printInOrder(root->right);
}

int main()
{
    Solution solution;

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    TreeNode *root = solution.buildTree(preorder, inorder);
    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
