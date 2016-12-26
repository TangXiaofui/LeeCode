#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int SumRootToleaf(TreeNode *root)
	{
		return SumRootToleaf(root,0);
	}
	int SumRootToleaf(TreeNode *root,int sum)
	{
		if (root == NULL)
		{
			return 0;
		}
		if (root->left == NULL &&root->right == NULL)
		{
			return sum*10 + root->value;
		}

		return SumRootToleaf(root->left,sum*10+root->value) +
				SumRootToleaf(root->right,sum*10+root->value);
	}
	
};


int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3};
	TreeNode *root = NULL;
	root = MakeTree(root,v,0);
	Solution s;
	cout <<s.SumRootToleaf(root);
	cout << endl;
	return 0;
}