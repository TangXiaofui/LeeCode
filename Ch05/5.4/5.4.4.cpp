#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:	
	vector<vector<int>> PathSum(TreeNode *root,int sum)
	{
		vector<vector<int>> result;
		vector<int> cur;
		PathSum(root,sum,cur,result);
		return result;
	}
	void PathSum(TreeNode *root,int sum,std::vector<int> &cur,std::vector<std::vector<int>> &result)
	{
		if (root == 0 || sum < 0)
		{
			return ;
		}
		cur.push_back(root->value);
		if (root->left == NULL && root->right == NULL)
		{
			if (sum == root->value)
			{
				result.push_back(cur);
			}		
		}
		PathSum(root->left,sum - root->value,cur,result);
		PathSum(root->right,sum - root->value,cur,result);
		cur.pop_back();
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {5,4,8,11,'#',13,4,7,2,'#','#','#','#','#',5,1};
	TreeNode *root = NULL;
	root = MakeTree(root,v,0);
	MidListAllNode(root);
	cout << endl;

	std::vector<std::vector<int> > result;
	Solution s;
	result = s.PathSum(root,22);
	for(auto r : result)
	{	
		for(auto e: r)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	return 0;
}