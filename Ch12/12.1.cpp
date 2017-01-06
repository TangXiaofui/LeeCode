#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool JumpGame(int a[],int n)
	{
		int reach = 1;
		for (int i = 0; i < reach && reach < n; ++i)
		{
			reach = max(reach,i+1+a[i]);
		}
		return reach >= n;
	}
	
};

int main(int argc, char const *argv[])
{
	int a[] = {2,3,1,0,4};
	int b[] = {3,2,1,0,4};
	Solution s;
	cout << s.JumpGame(a,5) << endl;
	cout << s.JumpGame(b,5)<< endl;
	return 0;
}