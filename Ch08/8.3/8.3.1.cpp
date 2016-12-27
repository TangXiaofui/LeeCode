#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> NextPermutation(std::vector<int> v)
	{
		std::vector<std::vector<int>> result;
		sort(v.begin(), v.end());
		do{
			result.push_back(v);
		}while(next_permutation(v.begin(), v.end()));
		return result;
	}
};


int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,1,2};
	Solution s;
	auto result = s.NextPermutation(v);
	PrintElem(result);
	return 0;
}