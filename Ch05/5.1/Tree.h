#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode *next;
    TreeNode(int v):value(v),left(nullptr),right(nullptr){}
};

TreeNode* MakeTree(TreeNode *root,vector<int> &vi,int pos)
{
    if(vi[pos] == '#' || pos >= vi.size() )
        return NULL;
    if(root == NULL)
    {
        root = new TreeNode(vi[pos]);
    }
    root->left = MakeTree(root->left,vi,2*pos+1);
    root->right = MakeTree(root->right,vi,2*pos+2);
    return root;
}

void ListAllNode(TreeNode *root)
{
    if(root != nullptr)
    {
        ListAllNode(root->left);
        cout << root->value << " ";
        ListAllNode(root->right);
    }
}
#endif