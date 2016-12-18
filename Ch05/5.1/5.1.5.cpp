#include "Tree.h"

class Solution{
public:
    TreeNode *pre = NULL,*p = NULL,*q = NULL;
    void RecoverNode(TreeNode *root)
    {
        dfs(root);
        int tmp = p->value;
        p->value = q->value;
        q->value = tmp;
    }
    void dfs(TreeNode *root)
    {
        if(!root)
            return ;
        if(root->left)
            dfs(root->left);
        if(pre && pre->value > root->value)
        {
                if(p == NULL)
                {
                    p = pre;
                    q = root;
                }
                else
                    q = root;
        }
        pre = root;
        if(root->right)
            dfs(root->right);
    }
};


int main(int argc,char *argv[])
{
    TreeNode *root = makeTree1();
    ListAllNode(root);
    cout << endl;
    Solution s;
    s.RecoverNode(root);
    ListAllNode(root);
     cout << endl;
}