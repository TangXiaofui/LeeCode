#include "../5.1/Tree.h"
using namespace std;


int main(int argc, char *argv[])
{
	vector<int> v1 = {5,3,7,2,4,6,8 };
	TreeNode *root = NULL;
	root = MakeTree(root, v1, 0);
	MidListAllNode(root);
	cout << endl;
}