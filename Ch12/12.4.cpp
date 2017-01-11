#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int BestTimeToBuyAndSellStockII(std::vector<int> prices)
	{
		int diff = 0 ;
		int profit = 0;
		int n = prices.size();
		for (int i = 1; i < n; ++i)
		{
			diff = prices[i] - prices[i-1];
			if (diff > 0)
			{
				profit +=  diff;
			}
		}
		return profit;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v={2,3,1,2,4,6};
	Solution s;
	cout << s.BestTimeToBuyAndSellStockII(v)<< endl;
}