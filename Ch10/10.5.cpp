#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int SolvedNQueenII(int n)
	{
		int iCount = 0;
		col.resize(n,0);
		diagCol.resize(2*n,0);
		CorCol.resize(2*n,0);
		dfs(n,0,iCount);
		return iCount;
	}
	void dfs(int n, int row, int &iCount)
	{
		if (n == row)
		{
			iCount++;
			return ;
		}
		for (int i = 0; i < n; ++i)
		{
			bool ok = col[i] == 0 && diagCol[row + i] == 0 && CorCol[row - i + n] == 0;
			if (ok)
			{
				col[i] = 1;
				diagCol[row + i] = 1;
				CorCol[row - i + n] = 1;
				dfs(n,row + 1,iCount);
				col[i] = 0;
				diagCol[row + i] = 0;
				CorCol[row - i + n] = 0;
			}
		}
	}
private:
	std::vector<int> col;
	std::vector<int> diagCol;
	std::vector<int> CorCol;
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.SolvedNQueenII(5) << endl;
	return 0;
}