#include "Tree.h"

class Solution{
public:
    bool isBalance(TreeNode *root)
    {
        return GetHeight(root) >= 0;
    }
    int GetHeight(TreeNode *root)
    {
        if( root == NULL)
            return 0;
        int left = GetHeight(root->left);
        int right = GetHeight(root->right);
        if(left < 0 || right < 0 || abs(left - right) > 1)
            return -1;
        return max(left,right) + 1;
    }
};
int main(int argc,char *argv[])
{
    vector<int> v1 = {3,4,'#',3,'#',6,7,1,2};
    TreeNode *root = NULL;
    root = MakeTree(root,v1,0);
    ListAllNode(root);
    cout << endl;

    Solution s;
    cout << s.isBalance(root) << endl;
    return 0;
}