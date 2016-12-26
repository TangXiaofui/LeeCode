#include "../5.1/Tree.h"
using namespace std;

<<<<<<< HEAD
=======
class Solution {
public:
	int MaxPathSum(TreeNode *root)
	{
		max_num= INT_MIN;
		dfs(root);
		return max_num;
	}
private:
	int max_num ;
	int dfs(TreeNode *root)
	{
		if (root == NULL)
		{
			return 0;
		}

		int sum = root->value;
		int l = dfs(root->left);
		int r = dfs(root->right);
		if (l > 0)
		{
			sum += l;
		}
		if (r > 0)
		{
			sum += r;
		}
		max_num = max(sum, max_num);

		return max(r, l) > 0 ? max(r, l) + root->value : root->value;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1, 2, 3, 4, 5};
	TreeNode *root = NULL;
	root = MakeTree(root, v, 0);
	MidListAllNode(root);
	cout << endl;

	Solution s;
	cout << s.MaxPathSum(root) << endl;

	return 0;
}
>>>>>>> 9cdc51429dcfddbc2db088fb09818783947f9cbd
