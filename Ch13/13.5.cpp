#include "13.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};

	int BestTimetoBuyandSellStockIII(std::vector<int> stock)
	{
		int n = stock.size();
		std::vector<int> f(n,0);
		std::vector<int> g(n,0);
		for (int i = 1,tmp = stock[0]; i < n; ++i)				//这里一大一小，股票才不会选择一样。
		{
			tmp = min(tmp,stock[i]);
			f[i] = max(f[i-1],stock[i]-tmp);
		}
		for (int i = n-2,tmp = stock[n-1]; i >= 0; --i)
		{
			tmp = max(tmp,stock[i]);
			g[i] = max(g[i+1],tmp-stock[i]);
		}
		int result = 0;
		for (int i = 0; i < n; ++i)
		{
			result = max(result,g[i]+f[i]);
		}
		return result;
	}
};


int main(int argc, char const *argv[])
{
	std::vector<int> v = {2,1,4,5,2,7};
	Solution s;
	cout << s.BestTimetoBuyandSellStockIII(v) << endl;

	return 0;
}