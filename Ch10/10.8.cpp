#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> CombinationSum(std::vector<int> nums,int sum)
	{
		sort(nums.begin(), nums.end());
		std::vector<std::vector<int>> result;
		std::vector<int> path;
		dfs(nums,0,sum,path,result);
		return result;
	}
	void dfs(std::vector<int> &nums,int start,int sum,std::vector<int> path,std::vector<std::vector<int>> &result)
	{
		if (sum == 0)
		{
			result.push_back(path);
			return ;
		}
		int preview = -1;
		for (int i = start; i < nums.size(); ++i)
		{
			if (sum < nums[i])
			{
				return ;
			}
			if (preview == nums[i])
			{
				continue;
			}
			preview = nums[i];
			path.push_back(nums[i]);
			dfs(nums,i+1,sum-nums[i],path,result);
			path.pop_back();
		}
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {10,1,2,7,6,1,5};
	Solution s;
	auto result = s.CombinationSum(nums,8);
	for(auto res : result)
	{
		for(auto e : res)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}