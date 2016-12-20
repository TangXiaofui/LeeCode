#include "Tree.h"

class Solution{
public:
    void connect(TreeNode *root)
    {
        const int n = GetLength(root);
        vector<vector<TreeNode *>> result(n);
        levelOrder(root,0,result);
        for(auto level:result)
        {
            for(auto it = level.begin();it != prev(level.end());it++)
            {
                (*it)->next = *next(it);
            }
            (*prev(level.end()))->next = NULL;
        }
    }
    void levelOrder(TreeNode *root,int level,vector<vector<TreeNode *>> &result)
    {
        if(root == NULL)
            return ;
        result[level].push_back(root);
        levelOrder(root->left,level+1,result);
        levelOrder(root->right,level+1,result);
    }
    int GetLength(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int left = GetLength(root->left);
        int right = GetLength(root->right);
        return max(left,right)+1;
    }
};

int main(int argc,char *argv[])
{
    vector<int> v1 = {1,2,3,4,5,'#',7};
    TreeNode *root = NULL;
    root = MakeTree(root,v1,0);
    ListAllNode(root);
    cout << endl;

    Solution s;
    s.connect(root);

    TreeNode *tmp = root->left;
    while(tmp)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    cout << endl;

    return 0;
}