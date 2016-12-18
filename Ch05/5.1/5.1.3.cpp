#include "Tree.h"

class Solution{
public:
    vector<vector<int>> BinaryTreeZigzagLevelOrderTraversal(TreeNode *root)
    {
        vector<vector<int>> result;
        queue<TreeNode *> cur,next;
        bool br = false;
        vector<int> level;
        cur.push(root);
        while(!cur.empty())
        {
            while(!cur.empty())
            {
                TreeNode *node = cur.front();
                cur.pop();
                level.push_back(node->value);
                if(node->left)
                    next.push(node->left);
                if(node->right)
                    next.push(node->right);
            }
            if(br)
                reverse(level.begin(),level.end());
            result.push_back(level);
            level.clear();
            swap(cur,next);
            br = !br;
        }
        return result;
    }
};


class Solution2{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        vector<int> level;
        vector<vector<int>> result;
        q.push(root);
        q.push(nullptr);
        bool br = false;
        while(!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            if(cur)
            {
                level.push_back(cur->value);
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
            }
            else
            {
                if(br)
                {
                    reverse(level.begin(),level.end());
                }
                result.push_back(level);
                level.clear();
                br = !br;
                if(!q.empty())
                    q.push(nullptr);
            }
        }
        return result;
    }
};

int main(int argc,char *argv[])
{
    TreeNode *root = NULL;
    root = makeTree();
    ListAllNode(root);
    cout << endl;
    

    Solution s;
    vector<vector<int>> result;
    //result = s.BinaryTreeZigzagLevelOrderTraversal(root);
    Solution2 s2;
    result = s2.zigzagLevelOrder(root);
    for(auto r:result)
    {
        for(auto s:r)
        {
            if(s >= 0)
                cout << s << " ";
        }
        cout << endl;
    }
    return 0;
}