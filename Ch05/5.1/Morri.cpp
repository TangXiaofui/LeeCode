#include "Tree.h"

class Solution{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        TreeNode *prev = NULL;
        while(root)
        {
            if(root->left == NULL)
            {
                result.push_back(root->value);
                root = root->right;
            }
            else
            {
                prev = root->left;
                while(prev->right != NULL && prev->right != root)
                {
                    prev = prev->right;
                }
                if(prev->right == NULL)
                {
                    prev->right = root;
                    root = root->left;
                }
                else
                {
                    result.push_back(root->value);
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return result;
    }
};

int main(int argc,char *argv[])
{
    vector<int> vi = {3,9,20,'#','#',15,7};
    TreeNode *root = NULL;
    root = MakeTree(root,vi,0);
    ListAllNode(root);
    cout << endl;

    Solution s;
    vector<int> result;
    result = s.inorderTraversal(root);
    for(auto e:result)
        cout << e << " ";
    cout << endl;
    return 0;
}