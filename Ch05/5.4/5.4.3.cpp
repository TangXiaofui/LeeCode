#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool hasPathValue(TreeNode *root,int sum)
	{
		if (root == NULL)
		{
			return sum == 0;
		}
		return hasPathValue(root->left,sum - root->value) || hasPathValue(root->right,sum - root->value);
	}
	
};


int main(int argc, char const *argv[])
{
	std::vector<int> v = {5,4,8,11,'#',13,4,7,2,'#','#','#','#','#',1};
	TreeNode *root = NULL;
	root = MakeTree(root,v,0);
	MidListAllNode(root);
	cout << endl;
	Solution s;
	cout << s.hasPathValue(root,22) << endl;
	return 0;
}