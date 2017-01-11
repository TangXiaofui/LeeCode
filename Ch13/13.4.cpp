#include "13.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int MaxArea(std::vector<int> heights)
	{
		heights.push_back(0);
		int n = heights.size();
		stack<int> s;
		int area = 0;
		for (int i = 0; i < n;)
		{
			if (s.empty() || heights[i] > heights[s.top()])
			{
				s.push(i++);
			}
			else
			{
				int tmp = s.top();
				s.pop();
				area = max(area, (s.empty() ? i : i - s.top() -1 ) * heights[tmp]);
			}
		}
		return area;
	}
	int GetMaxArea(std::vector<std::vector<int>> &matrix)
	{
		int m = matrix.size();
		int n = matrix[0].size();
		std::vector<int> tmp(n,0);
		int result = 0;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == 0)
				{
					tmp[j] = 0;
				}
				else
				{
					tmp[j]++;
				}
			}
			result = max(result,MaxArea(tmp));
		}
		return result;
	}
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> matrix = {
		{1,0,0,0,0},
		{1,0,1,1,1},
		{0,1,1,1,1},
		{0,1,0,0,0}
	};
	Solution s;
	cout << s.GetMaxArea(matrix) << endl;

	return 0;
}