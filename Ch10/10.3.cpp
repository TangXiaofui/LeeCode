#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int UniquePathII(std::vector<std::vector<int>> &obstacleGrid)
	{
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		this->f = std::vector<std::vector<int>>(m+1,std::vector<int>(n+1,0));
		return dfs(m,n,obstacleGrid);
	}
private:
	std::vector<std::vector<int>> f;
	int dfs(int m,int n,std::vector<std::vector<int>> &obstacleGrid)
	{
		if (m < 1 || n < 1 )
		{
			return 0;
		}
		if (m == 1 && n == 1)
		{
			return 1;
		}
		if (obstacleGrid[m-1][n-1] > 0)
		{
			return 0;
		}
		return getUniquePath(m-1,n,obstacleGrid) + getUniquePath(m,n-1,obstacleGrid);
	}
	int getUniquePath(int x,int y,std::vector<std::vector<int>> &obstacleGrid)
	{
		if (f[x][y] > 0)
		{
			return f[x][y];
		}
		return f[x][y] = dfs(x,y,obstacleGrid);
	}
};


int main(int argc, char const *argv[])
{
	Solution s;
	int m = 3;
	int n = 3;
	std::vector<std::vector<int>> v(m,std::vector<int>(n,0));
	v[1][1] = 1;
	cout << s.UniquePathII(v) << endl;
	return 0;
}