#include "../5.1/Tree.h"
using namespace std;

class Solution
{
public:
	TreeNode* SortedListToBST(TreeNode *root)
	{
		int len = 0;
		TreeNode *p = root;
		while(p)
		{
			len++;
			p = p->next;
		}
		return SortedListToBST(root,0,len);
	}
	TreeNode *SortedListToBST(TreeNode *&root,int first,int last)
	{
		if (first == last)
		{
			return NULL;
		}
		int mid = first + (last - first)/2;
		TreeNode *left = SortedListToBST(root,first,mid);
		TreeNode *parent = new TreeNode(root->value);
		parent->left = left;
		root = root->next;
		parent->right = SortedListToBST(root,mid+1,last);
		return parent;
	}
};

int main(int argc, char const *argv[])
{
	TreeNode *head = NULL;
	TreeNode *p = NULL;
	head = new TreeNode(1);
	p = head;
	for (int i = 0; i < 7; ++i)
	{
		p->next = new TreeNode(i+2);
		p = p->next;
	}
	p = head;
	while(p)
	{
		cout << p->value << " " ;
		p = p->next;
	}
	cout << endl;
	cout << "----" << endl;
	Solution s;
	TreeNode *root = NULL;
	root = s.SortedListToBST(head);
	MidListAllNode(root);
	cout << endl;
	return 0;
}