#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	void connect(TreeNode *root)
	{
		connect(root,NULL);
	}
	void connect(TreeNode *root,TreeNode *sibling)
	{
		if (root == NULL)
		{	
			return;
		}
		else
		{
			root->next = sibling;
		}

		connect(root->left,root->right);
		if (sibling)
		{
			connect(root->right,sibling->left);
		}
		else
			connect(root->right,NULL);
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	TreeNode *root = NULL;
	root = MakeTree(root,v,0);

	Solution s;
	s.connect(root);
	TreeNode *p = root;
	while(p)
	{
		TreeNode *t = p;
		while(t)
		{
			cout << t->value << " ";
			t = t->next;
		}
		cout << endl;
		p = p->left;
	}

	return 0;
}