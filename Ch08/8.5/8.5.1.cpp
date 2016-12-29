#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> Combination(int n,int k)
	{
		std::vector<std::vector<int>> result;
		std::vector<int> path;
		Combination(n,k,1,0,path,result);
		return result;
	}
	void Combination(int n,int k ,int start,int cur,std::vector<int> &path,std::vector<std::vector<int>> &result)
	{
		if (k == cur)
		{
			result.push_back(path);
			return ;
		}
		for (int i = start; i <= n; ++i)
		{
			path.push_back(i);
			Combination(n,k,i+1,cur+1,path,result);
			path.pop_back();
		}
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> result;
	Solution s;
	result = s.Combination(4,2);
	PrintElem(result);
	return 0;
}