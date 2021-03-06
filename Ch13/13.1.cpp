#include "13.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int Triangle(std::vector<std::vector<int>> &triangle)
	{
		for (int i = triangle.size()-2; i >= 0; i--)
		{
			for (int j = 0; j < i+1; ++j)
			{
				triangle[i][j] += min(triangle[i+1][j],triangle[i+1][j+1]);
			}
		}
		return triangle[0][0];
	}
};


int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> t = {
		{2},
		{3,4},
		{6,5,7},
		{4,1,8,3}
	};
	Solution s;
	cout << s.Triangle(t)<<endl;
	return 0;
}