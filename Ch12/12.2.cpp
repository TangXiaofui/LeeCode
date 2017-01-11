#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int JumpGameII(int a[], int n)
	{
		int left = 0;
		int right = 0;
		int step = 0;
		while(left <= right)
		{
			step++;
			int old_right = right;
			for (int i = left; i <= old_right; ++i)			// =
			{
				int new_right = i + a[i] ;
				if (new_right >= n-1)						// =
				{
					break;
				}
				if (new_right > right)
				{
					right = new_right;
				}
			}
			left = old_right+1;
		}
		return step;
	}
	
};

int main(int argc, char const *argv[])
{
	int a[] = {2,3,1,1,4};
	Solution s;
	cout << s.JumpGameII(a,5) << endl;
	return 0;
}
