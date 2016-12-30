#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int UniquePath(int m,int n)
	{
		this->f = std::vector<std::vector<int>>(m+1,std::vector<int>(n+1,0));
		return dfs(m,n);
	}
private:
	std::vector<std::vector<int>> f;
	int dfs(int m,int n)
	{
		if (m <= 0 || n <= 0)
		{
			return 0;
		}
		if (m == 1 && n == 1)
		{
			return 1;
		}
		return GetUniquePath(m-1,n) + GetUniquePath(m,n-1);
	}
	int GetUniquePath(int x,int y)
	{
		if (f[x][y] > 0)
		{
			return f[x][y];
		}
		return f[x][y] = dfs(x,y);
	}
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.UniquePath(2,2) << endl;
	return 0;
}