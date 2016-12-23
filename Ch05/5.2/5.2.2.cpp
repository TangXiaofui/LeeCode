#include "../5.1/Tree.h"

class Solution{
public:
    TreeNode *BuildTree(vector<int> InOrder,vector<int> PostOrder)
    {
        return BuildTree(InOrder.begin(),InOrder.end(),PostOrder.begin(),PostOrder.end());
    }
    template <typename InputType>
    TreeNode *BuildTree(InputType in_first,InputType in_last,InputType post_first,InputType post_last)
    {
        if(in_first == in_last )
            return NULL;
        if(post_first == post_last)
            return NULL;
        TreeNode *root = new TreeNode(*prev(post_last));
        auto tmp = find(in_first,in_last,*prev(post_last));
        int dist = distance(in_first,tmp);
        root->left = BuildTree(in_first,next(in_first,dist),post_first,next(post_first,dist));
        root->right = BuildTree(next(in_first,dist+1),in_last,next(post_first,dist),prev(post_last));
        return root;
    }
};


int main(int argc,char *argv[])
{   
    TreeNode *root = NULL;
    vector<int> v1 = {1,2,3,4,5,6,7};
    root = MakeTree(root,v1,0);

    PreListAllNode(root);
    cout << endl;

    MidListAllNode(root);
    cout << endl;

    PostListAllNode(root);
    cout << endl;

    vector<int> InOrder = {4,2,5,1,6,3,7};
    vector<int> PostOrder = {4,5,2,6,7,3,1};
    Solution s;
    TreeNode *newRoot;
    newRoot = s.BuildTree(InOrder,PostOrder);
    PreListAllNode(newRoot);
    cout << endl;
    return 0;
}