#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;
class Solution{
public:
	int ThreeSumClosest(vector<int> nums)
	{
		int result;
		if(nums.size() < 3)
			return 0;
		sort(nums.begin(),nums.end());
		const int target = 1;
		int min = INT_MAX;
		auto last = nums.end();
		for(auto a = nums.begin(); a < prev(last,2) ; a = upper_bound(a,prev(last,2),*a) )
		{
			auto b = next(a);
			auto c = prev(last);
			while(b < c)
			{
				int sum = *a + *b + *c;
				int gap = abs(target - sum);
				if(gap < min )
				{
					result = sum;
					min = gap;
				}

				if(sum > target)
					c = prev(lower_bound(b,c,*c)); 
				else
					b = next(upper_bound(b,c,*b));
			}	
		}
		return result;
	}
};


int main(int argc,char *argv[])
{
	vector<int> nums = {-1,2,1,4};
	Solution s;
	int result;
	result = s.ThreeSumClosest(nums);
	cout << "result = " << result << endl;
	return 0;
}
