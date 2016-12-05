#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

class Solution{
public:
	vector<vector<int>> FourSum(vector<int> nums,int target)
	{
		if(nums.size() < 4)
			return vector<vector<int>> ();
		sort(nums.begin(),nums.end());

		map<int,vector<pair<int,int>>> cache;
		for(size_t a = 0 ; a < nums.size() ; a++)
			for(size_t b = a+1; b < nums.size() ; b++ )
			{
				cache[nums[a]+nums[b]].push_back(pair<int,int>{a,b});
			}
		set<vector<int>> result;
		for(size_t c = 2;c < nums.size() ;c++)
			for(size_t d = c+1; d < nums.size();d++)
			{
				int key = target - nums[c] - nums[d];
				if(cache.find(key) != cache.end())
				{
					for(int k = 0 ; k < cache[key].size();k++)
					{
						if(cache[key][k].second >= c)
							continue;
						result.insert(vector<int>{nums[cache[key][k].first],nums[cache[key][k].second],nums[c],nums[d]});
					}
				} 
			}

		return vector<vector<int>> (result.begin(),result.end());
	}
};

int main(int argc,char *argv[])
{
	vector<int> nums = {1,0,-1,0,-2,2};
	Solution s;
	vector<vector<int>> result;
	result = s.FourSum(nums,0);
	for(auto res:result)
	{
		for(auto i : res)
			cout << i << " ";
		cout << endl; 
	}
	return 0;
}
