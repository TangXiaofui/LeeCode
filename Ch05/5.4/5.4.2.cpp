#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int maxDepth(TreeNode *root)
	{
		if (root == NULL)
		{
			return  0;
		}
		return max(maxDepth(root->left),maxDepth(root->right))+1;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3,4,'#',5,6,'#',7};
	TreeNode *root = NULL;
	root = MakeTree(root,v,0);
	PreListAllNode(root);
	cout << endl;
	Solution s;
	cout << s.maxDepth(root) << endl;
	return 0;
}