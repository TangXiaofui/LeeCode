#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	void nextPermutation(vector<int> &nums)
	{
		next_permutation(nums.begin(),nums.end());		
	}
	template<typename InIt> 
	bool next_permutation(InIt first,InIt last)
	{
		const auto rfirst = reverse_iterator<InIt>(last);
		const auto rlast = reverse_iterator<InIt>(first);
		auto pivet = next(rfirst);
	
		while(pivet != rlast && *pivet > *prev(pivet))
			pivet = next(pivet);
			
		if(pivet == rlast)
		{
			reverse(first,last);
			return false;
		}
		auto change = find_if(rfirst,pivet,bind1st(less<int>(),*pivet));
		swap(*change,*pivet);
		reverse(rfirst,pivet);
		return true;
	}
	template<typename Init>
	void printVector(Init first,Init last)
	{
		while(first != last)
			cout << *first++ << " ";
		cout << endl;
	}
};


int main(int argc,char *argv[])
{
	vector<int> nums = {6,8,7,4,3,2};
	Solution s;
	s.nextPermutation(nums);
	s.printVector(nums.begin(),nums.end());
	return 0;
}
