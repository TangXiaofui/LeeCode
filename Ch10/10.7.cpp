#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> CombinationSum(std::vector<int> nums,int sum)
	{
		std::vector<std::vector<int>> result;
		std::vector<int> path;
		sort(nums.begin(), nums.end());	
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

		if (sum < nums[start])
		{
			return ;
		}

		for (int i = start; i < nums.size(); ++i)
		{
			path.push_back(nums[i]);
			dfs(nums,i,sum-nums[i],path,result);
			path.pop_back();
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> nums = {2,3,6,7};
	Solution s;
	auto result = s.CombinationSum(nums,7);
	for(auto res : result)
	{
		for(auto e : res)
			cout << e <<" ";
		cout << endl;
	}
	return 0;
}