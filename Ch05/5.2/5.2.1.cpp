#include "../5.1/Tree.h"

class Solution{
public:
    TreeNode *BuildTree(vector<int> &PreOrder,vector<int> &InOrder)
    {
        return BuildTree(PreOrder.begin(),PreOrder.end(),InOrder.begin(),InOrder.end());
    }
    template <typename InputType>
    TreeNode *BuildTree(InputType pre_first,InputType pre_last,InputType in_first,InputType in_last)
    {
        if(pre_first == pre_last)
            return NULL;
        if(in_first == in_last)
            return NULL;
        
        auto RootPos = find(in_first,in_last,*pre_first);
        int RootDistance = distance(in_first,RootPos);

        TreeNode *root = new TreeNode(*pre_first);
        root->left = BuildTree(next(pre_first),next(pre_first,RootDistance+1),in_first,next(in_first,RootDistance));
        root->right = BuildTree(next(pre_first,RootDistance+1),pre_last,next(RootPos),in_last);
        return root;
    }
};



int main(int argc,char *argv[])
{
    vector<int> PreOrder = {1,2,4,5,3,6,8,7};
    vector<int> InOrder = {4,2,5,1,6,8,3,7};
    TreeNode *root;
    Solution s;
    root = s.BuildTree(PreOrder,InOrder);
    ListAllNode(root);
    cout << endl;


    return 0;
}