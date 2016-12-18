#include "Tree.h"

class Solution{
public:
    vector<vector<int>> LevelOrder(TreeNode *root)
    {
        int height = GetHeight(root);
        vector<vector<int>> result(height);
        getSolution(root,0,result);
        return result;
    }

    void getSolution(TreeNode* root,int level,vector<vector<int>> &result)
    {
        if(root == nullptr)
            return ;
        result[level].push_back(root->value);
        getSolution(root->left,level+1,result);
        getSolution(root->right,level+1,result);
    }
    int GetHeight(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        int left = GetHeight(root->left);
        int right = GetHeight(root->right);
        int height = (left > right ? left : right)+1;
        return height;
    }
};



class Solution2{
public:
    vector<vector<int>> LevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        vector<int> level;
        queue<TreeNode*> count,next;
        count.push(root);
        while(!count.empty())
        {
            while(!count.empty())
            {
                TreeNode *f = count.front();
                count.pop();
                level.push_back(f->value);
                if(f->left != nullptr)
                    next.push(f->left);
                if(f->right != nullptr)
                    next.push(f->right);
            }
            result.push_back(level);
            level.clear();
            swap(count,next);
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main(int argc,char *argv[])
{
    TreeNode *root = makeTree();
    ListAllNode(root);
    cout << endl;
    vector<vector<int>> result;
    Solution2 s;
    result = s.LevelOrder(root);
    for(auto r:result)
    {
        for(auto e: r)
        {
            if(e >= 0)
                cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}