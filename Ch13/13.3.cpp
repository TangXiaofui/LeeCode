#include "13.h"
using namespace std;

class Solution
{
public:
	Solution() {};
	~Solution() {};
	int MinCut(string s)
	{
		const int n = s.size();
		std::vector<std::vector<bool>> isParlime(n, std::vector<bool>(n, false));
		std::vector<int> f(n + 1);
		for (int i = 0; i <= n; ++i)
		{
			f[i] = n - i - 1;
		}
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				if (s[i] == s[j] && (j - i < 2 || isParlime[i + 1][j - 1]))
				{
					isParlime[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
	}
};

int main(int argc, char const *argv[])
{
	string str = "aabaa";
	Solution s;
	cout << s.MinCut(str) << endl;
	return 0;
}