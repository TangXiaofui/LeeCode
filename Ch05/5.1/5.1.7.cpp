#include "Tree.h"
class Solution{
public:
    bool isSymmetrix(TreeNode *root)
    {
        return root == NULL ? false : isSymmetrix(root->left,root->right);
    }
    bool isSymmetrix(TreeNode *left,TreeNode *right)
    {
        if(!left && !right)
            return true;
        if(!left || !right)
            return false;
        return left->value == right->value && isSymmetrix(left->left,right->right) && isSymmetrix(left->right,right->left);
    }
};

class Solution2{
public:
    bool isSymmetrix(TreeNode *root)
    {
        stack<TreeNode *> stk;
        stk.push(root->left);
        stk.push(root->right);
        while(!stk.empty())
        {
            TreeNode *p = stk.top();
            stk.pop();
            TreeNode *q = stk.top();
            stk.pop();

            if(!p && !q)
                continue;
            if(!p || !q)
                return false;
            if(p->value != q->value)
                return false;
            stk.push(p->left);
            stk.push(q->right);
            
            stk.push(p->right);
            stk.push(q->left);
        }
        return true;
    }
};

int main(int argc,char *argv[])
{
    vector<int> v1 = {3,4,4,6,5,5,6,'#',7,'#','#','#','#',7,'#'};
    TreeNode *root = NULL;
    root  = MakeTree(root,v1,0);
    ListAllNode(root);
    cout << endl;
    Solution2 s;
    cout << s.isSymmetrix(root);

    return 0;
}