#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v):value(v),left(nullptr),right(nullptr){}
};

TreeNode *makeTree()
{
    TreeNode *root = nullptr;
    static int i = 0;

    root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    return root;
}

TreeNode *makeTree1()
{
    TreeNode *root = nullptr;
    static int i = 0;

    root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);

    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(7);

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