#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> SubsetsII(std::vector<int> v)
	{
		sort(v.begin(), v.end());
		set<std::vector<int>> setResult;
		int n = v.size();
		std::vector<int> path;
		for (int i = 0; i < 1 << n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i & 1 << j)
				{
					path.push_back(v[j]);
				}
			}
			setResult.insert(path);
			path.clear();
		}
		return std::vector<std::vector<int>>(setResult.begin(), setResult.end());
	}	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,1,1};
	Solution s;
	std::vector<std::vector<int>> result;
	result = s.SubsetsII(v);
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
