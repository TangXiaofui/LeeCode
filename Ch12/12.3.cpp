#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int BestTimeToBuyAndSellStock(std::vector<int> prices)
	{
		int cur_min = prices[0];
		int n = prices.size();
		int profit = 0;
		for (int i = 1; i < n; ++i)
		{
			profit = max(profit, prices[i]-cur_min);
			cur_min = min(prices[i],cur_min);
		}
		return profit;
	}
	
};


int main(int argc, char const *argv[])
{
	std::vector<int> v={2,3,1,2,4,6};
	Solution s;
	cout << s.BestTimeToBuyAndSellStock(v)<< endl;
	return 0;
}