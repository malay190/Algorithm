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

TreeNode *build(vector<int> &inorder, vector<int> &postorder, int &postIndex, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return nullptr;

    int val = postorder[postIndex--];
    int inMid = find(inorder.begin(), inorder.end(), val) - inorder.begin();

    TreeNode *root = new TreeNode(val);

    root->right = build(inorder, postorder, postIndex, inMid + 1, inEnd);
    root->left = build(inorder, postorder, postIndex, inStart, inMid - 1);

    return root;
}

TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int postIndex = postorder.size() - 1;
    return build(inorder, postorder, postIndex, 0, inorder.size() - 1);
}

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

    // Example: Input postorder and inorder traversal
    vector<int> postorder = {9, 15, 7, 20, 3}; // Left -> Right -> Root
    vector<int> inorder = {9, 3, 15, 20, 7};   // Left -> Root -> Right

    // Build the binary tree
    TreeNode *root = solution.buildTree(inorder, postorder);

    // Output the tree in inorder traversal (to verify correctness)
    cout << "Inorder traversal of the constructed tree: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
