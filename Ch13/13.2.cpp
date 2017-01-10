#include "13.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int MaxSubArray(std::vector<int> v)
	{
		int f = 0;
		int result = INT_MIN;
		for (int i = 0; i < v.size(); ++i)
		{
			f = max(f+v[i],v[i]);
			result = max(result,f);
		}
		return result;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};
	Solution s;
	cout << s.MaxSubArray(v) << endl;
	return 0;
}