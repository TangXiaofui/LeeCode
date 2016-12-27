#include "../8.h"
using namespace std;


class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> Permutation(std::vector<int> v)
	{
		sort(v.begin(), v.end());
		std::vector<std::vector<int>> result;
		do
		{
			result.push_back(v);
		}while(NextPermutation(v.begin(), v.end()));
		return result;
	}
	template <typename InputType>
	bool NextPermutation(InputType first,InputType last)
	{
		auto rfirst = reverse_iterator<InputType>(last);
		auto rend = reverse_iterator<InputType>(first);
		auto pivet = next(rfirst);
		while(pivet != rend && *pivet > *prev(pivet))
			pivet = next(pivet);
		if (pivet == rend)
		{
			reverse(rfirst,rend);
			return false;
		}

		auto change = find_if(rfirst,pivet,bind1st(less<int>(),*pivet));
		swap(*change,*pivet);
		reverse(rfirst,pivet);
		return true;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3};
	Solution s;
	auto result = s.Permutation(v);
	PrintElem(result);
	return 0;
}