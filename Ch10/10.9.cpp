#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<string> GenerateParenthess(int n)
	{
		std::vector<string> result;
		string path;
		dfs(n,0,0,path,result);
		return result;
	}
	void dfs(int n,int l,int r,string path,std::vector<string> &result)
	{
		if (l == n)
		{
			path.append(n-r,')');
			result.push_back(path);
			return ;
		}
		dfs(n,l+1,r,path+'(',result);
		if (l > r)
		{
			dfs(n,l,r+1,path+')',result);
		}
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	auto res = s.GenerateParenthess(3);
	for(auto e : res)
	{
		cout << e << endl;
	}
	return 0;
}