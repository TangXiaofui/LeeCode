#include "7.h"
using namespace std;
class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<int> SearchForRange(int a[] , int n, int target)
	{
		int* ibegin = lower_bound(a,a+n,target);
		int* iend = prev(upper_bound(a,a+n,target));
		if (*ibegin != target)
		{
			return std::vector<int>{-1,-1};
		}
		else
			return std::vector<int>{distance(a,ibegin),distance(a,iend)};
	}
	
};


class Solution2
{
public:
	Solution2(){};
	~Solution2(){};
	std::vector<int> SearchForRange(int a[],int n,int target)
	{
		int *ibegin = my_lower_bound(a,a+n,target);
		int *iend = prev(my_upper_bound(ibegin,a+n,target));
		if (*ibegin != target)
		{
			return std::vector<int>{-1,-1};
		}
		else
			return std::vector<int>{distance(a,ibegin),distance(a,iend)};
	}
	
	template<typename InputType,typename T>
	InputType my_lower_bound(InputType first,InputType last,T target)
	{
		while(first != last)
		{
			InputType mid = next(first,distance(first,last)/2);
			if (*mid >= target)
			{
				last = mid;
			}
			else
				first = ++mid;
		}	
		return first;
	}
	template<typename InputType,typename T>
	InputType my_upper_bound(InputType first,InputType last,T target)
	{
		while(first != last)
		{
			InputType mid = next(first,distance(first,last)/2);
			if (*mid > target)
			{
				last = mid;
			}
			else
				first = ++mid;
		}
		return first;	
	}

};


int main(int argc, char const *argv[])
{
	int a[] = {5,7,7,8,8,9};
	Solution2 s;
	std::vector<int> v = s.SearchForRange(a,sizeof(a)/sizeof(a[0]),8);
	for(auto i : v)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}