#include "../5.1/Tree.h"
using namespace std;

class Solution{
public:
	TreeNode *SortedArrayToBST(vector<int> &num)
	{
		return SortedArrayToBST(num,0,num.size());
	}
	TreeNode *SortedArrayToBST(std::vector<int> v,int first,int last)
	{

		if (first == last)
		{
			/* code */
			return NULL;
		}
		if (last - first == 1)
		{
			/* code */
			return new TreeNode(v[first]);
		}
		int mid = first + (last-first)/2;
		TreeNode *root = new TreeNode(v[mid]);
		root->left = SortedArrayToBST(v,first,mid);
		root->right = SortedArrayToBST(v,mid+1,last);

		return root;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> v = {1,2,3,4,5,6,7};
	Solution s;
	TreeNode *root = s.SortedArrayToBST(v);
	MidListAllNode(root);
	cout << endl;
	return 0;
}