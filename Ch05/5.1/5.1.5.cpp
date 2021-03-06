#include "Tree.h"

class Solution{
public:
    void RecoverNode(TreeNode *root)
    {
        TreeNode *prev,*tmp = NULL;
        pair<TreeNode *,TreeNode *> broken;
        while(root)
        {
            if(root->left == NULL)
            {
                detect(broken,tmp,root);
                tmp = root;
                root = root->right;
            }
            else
            {
                prev = root->left;
                while(prev->right != NULL && prev->right != root)
                    prev = prev->right;
                
                if(prev->right == NULL)
                {
                    prev->right = root;
                    root = root->left;
                }
                else
                {
                    detect(broken,tmp,root);
                    tmp = root;
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        //swap(broken.first->value,broken.second->value);
    }
    void detect(pair<TreeNode *,TreeNode *> &broken,TreeNode* first,TreeNode *second)
    {   
        if(first != NULL && first->value > second->value)
        {
            // if(broken.first == NULL)
            //     broken.first = first;
            swap(first->value,second->value);

        }
        broken.second = second;
    }
   
};


int main(int argc,char *argv[])
{
    vector<int> vi = {5,2,6,'#','#',7,8};
    TreeNode *root = NULL;
    root = MakeTree(root,vi,0);
    ListAllNode(root);
    cout << endl;

    Solution s;
    s.RecoverNode(root);
    ListAllNode(root);
    cout << endl;
    return 0;
}