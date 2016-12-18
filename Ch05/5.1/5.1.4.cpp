#include "Tree.h"

class Solution{
public:
    vector<int> solution(TreeNode *root)
    {
        vector<int> result;
        dfs(root,result);
        return result;
    }
    void dfs(TreeNode *root,vector<int> &result)
    {
        if(root == NULL)
            return;
        if(root->left)
            dfs(root->left,result);
        result.push_back(root->value);
        if(root->right)
            dfs(root->right,result);
    }
};

int main(int argc,char *argv[])
{
    TreeNode *root = NULL;
    root = makeTree();
    ListAllNode(root);
    cout << endl;
    
    Solution s;
    vector<int> result;
    result = s.solution(root);
    for(auto s:result)
    {
        if(s >= 0)
            cout << s << " ";
    }
    cout << endl;
    
    return 0;
}