#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> Subsets(std::vector<int> v)
	{
		sort(v.begin(),v.end());
		std::vector<std::vector<int>> result;
		std::vector<int> path;
		int n = v.size();
		for (int i = 0; i < 1 << n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i & 1 << j)
				{
					path.push_back(v[j]);
				}
			}
			result.push_back(path);
			path.clear();
		}
		return result;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> result;
	std::vector<int> v = {1,2,3};
	Solution s;
	result = s.Subsets(v);
	for(auto r : result)
	{
		for(auto e : r)
		{
			cout << e << " ";
		}
		cout << endl;
	}
	return 0;
}