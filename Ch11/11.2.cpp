#include "11.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int sqrt(int x)
	{
		int start = 1;
		int end = x;
		int mid_last;
		int mid;
		while(start < end)
		{
			mid = start + (end - start)/2;
			if (x / mid == mid)
			{
				mid_last = mid;
				break;
			}
			if (x / mid < mid)
			{
				end = mid;
			}
			if (x / mid > mid)
			{
				start = mid;
				mid_last = mid;
			}
		}
		return mid_last;
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.sqrt(25) << endl;
	return 0;
}