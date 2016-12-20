#include "Tree.h"

class Solution{
public:
    bool isTheSame(TreeNode *s1,TreeNode *s2)
    {
        if(!s1 && !s2)
            return true;
        if(!s1 || !s2)
            return false;

        return s1->value == s2->value && isTheSame(s1->left,s2->left) && isTheSame(s1->right,s2->right);
    }
};

class Solution2{
public:
    bool isTheSame(TreeNode *s1,TreeNode *s2)
    {
        stack<TreeNode*> stk;
        stk.push(s1);
        stk.push(s2);
        while(!stk.empty())
        {
            TreeNode *p1 = stk.top();
            stk.pop();
            TreeNode *p2 = stk.top();
            stk.pop();

            if(!p1 && !p2)
                continue;
            if(!p1 || !p2)
                return false;
            if(p1->value != p2->value)
                return false;
            
            stk.push(p1->left);
            stk.push(p2->left);
            
            stk.push(p1->right);
            stk.push(p2->right);
        }
    }
};
class Solution3{
public:
    vector<int> Inorder(TreeNode *root)
    {
        stack<TreeNode *> stk;
        vector<int> result;
        while(root != NULL ||!stk.empty())
        {
            if(root != NULL)
            {
                stk.push(root);
                root = root->left;
            }
            else
            {
                TreeNode *node = stk.top();
                stk.pop();
                result.push_back(node->value);
                root = node->right;
            }
        }
        return result;
    }
};
int main(int argc,char *argv[])
{
    vector<int> v1 = {3,9,20,'#','#',15,7};
    vector<int> v2 = {3,9,20,'#','#',15,7};
    vector<int> v3 = {3,9,20,'#','#',15};
    vector<int> v4 = {3,9,2,'#','#',15,7};
    TreeNode *r1 = NULL,*r2 = NULL,*r3 = NULL,*r4 = NULL;

    r1 = MakeTree(r1,v1,0);
    r2 = MakeTree(r2,v2,0);
    r3 = MakeTree(r3,v3,0);
    r4 = MakeTree(r4,v4,0);
    ListAllNode(r1);
    cout << endl;

    Solution3 s3;
    vector<int> result = s3.Inorder(r1);
    for(auto i : result)
        cout << i << " ";
    cout << endl;
/*
    ListAllNode(r2);
    cout << endl;

    ListAllNode(r3);
    cout << endl;

    ListAllNode(r4);
    cout << endl;

    Solution s;
    cout << s.isTheSame(r1,r2) << endl;
    cout << s.isTheSame(r1,r3) << endl;
    cout << s.isTheSame(r1,r4) << endl;
    
*/
    return 0;
}