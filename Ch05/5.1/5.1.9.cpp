#include "Tree.h"

class Solution{
public:
    void FlattenBinaryTreeToLinkList(TreeNode *root)
    {
        if(root == NULL)
            return;
        FlattenBinaryTreeToLinkList(root->left);
        FlattenBinaryTreeToLinkList(root->right);

        if(root->left == NULL)
            return ;
        TreeNode *p = root->left;
        while(p->right) p = p->right;
        p->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
};
int main(int argc,char *argv[])
{
    vector<int> v1 = {1,2,5,3,4,'#',6};
    TreeNode *root = NULL;
    root = MakeTree(root,v1,0);
    ListAllNode(root);
    cout << endl;
    Solution s;
    s.FlattenBinaryTreeToLinkList(root);
    while(root)
    {
        cout << root->value << " ";
        root = root->right;
    }
    cout << endl;
    return 0;
}