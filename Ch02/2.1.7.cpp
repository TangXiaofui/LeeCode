#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution{
public:
	vector< vector<int> > ThreeSum(vector<int> &nums)
	{
		vector< vector<int> > result;
		if(nums.size() < 3)
			return result;
		
		sort(nums.begin(),nums.end());

		const int target = 0;
		auto last = nums.end();
		for(auto a = nums.begin(); a < prev(last,2) ; a = upper_bound(a,prev(last,2),*a))
			for(auto b = next(a); b < prev(last) ; b = upper_bound(b,prev(last),*b))
			{
				int c = target - *a - *b ;
				if(binary_search(next(b),last,c))
				{
					result.push_back(vector<int> {*a,*b,c});
				}
			}
		return result;
	}
};


int main(int argc,char *argv[])
{
	vector<int> nums = {-1,0,1,2,-1,-4};
	Solution s;
	vector<vector<int>>  res;
	
	res=s.ThreeSum(nums);
	
	for(auto r:res)
	{
		for(auto i : r)
		{
			cout << i << " " ;
		}	
		cout << endl;
	}

	return 0;
}
