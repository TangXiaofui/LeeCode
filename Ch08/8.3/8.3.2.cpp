#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> RecurPermutation(std::vector<int> v)
	{
		sort(v.begin(), v.end());
		std::vector<int> path;
		std::vector<std::vector<int>> result;
		dfs(v,path,result);
		return result;
	}
	void dfs(std::vector<int> v,std::vector<int> &path,std::vector<std::vector<int>> &result)
	{
		for(auto i : v)
		{
			if (path.size() == v.size())
			{
				result.push_back(path);
				return ;
			}
			auto pos = find(path.begin(), path.end(),i);
			if (pos == path.end())
			{
				path.push_back(i);
				dfs(v,path,result);
				path.pop_back();
			}
		}
	}
};
int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3};
	Solution s;
	auto result = s.RecurPermutation(v);
	PrintElem(result);
	return 0;
}