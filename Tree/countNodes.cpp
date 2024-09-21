// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

                      };
};

int countNodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int count = countNodes(root);
    cout << count;
    return 0;
}