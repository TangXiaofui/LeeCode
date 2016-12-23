#include "../5.1/Tree.h"
using namespace std;
class Solution {
public :
	vector<TreeNode *> generateTree(int n)
	{
		return generateTree(1, n);
	}
	vector<TreeNode *> generateTree(int begin, int end)
	{
		vector<TreeNode *> subtree;
		if (begin > end)
		{
			subtree.push_back(nullptr);
			return subtree;
		}
		for (int k = begin ; k <= end; k++)
		{
			vector<TreeNode *> left = generateTree(begin, k - 1);
			vector<TreeNode *> right = generateTree(k + 1, end);
			
			for(auto i : left)
				for (auto j : right)
				{
					TreeNode *root = new TreeNode(k);
					root->left = i;
					root->right = j;
					subtree.push_back(root);
				}

		}
		return subtree;
	}
};


int main(int argc, char *argv[])
{
	Solution s;
	vector<TreeNode *> subtree = s.generateTree(3);
	cout << subtree.size();

	
	return 0;
}