#include "../5.1/Tree.h"
using namespace std;

class Solution {
public:
	bool isValidTree(TreeNode * root)
	{
		return isValidTree(root, INT_MIN, INT_MAX);
	}

	bool isValidTree(TreeNode *root , int iMin, int iMax)
	{
		if (root == NULL)
		{
			return true;
		}
		if (!(root->value > iMin && root->value < iMax))
		{
			return false;
		}
		return isValidTree(root->left, iMin, root->value) && isValidTree(root->right, root->value, iMax);
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *root = NULL;
	std::vector<int> v1 = {4, 2, 6, 1, 3, 5, 7};
	root = MakeTree(root, v1, 0);
	MidListAllNode(root);
	cout << endl;
	Solution s;
	cout << s.isValidTree(root) << endl;

	return 0;
}
