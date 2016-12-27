#include "7.h"
using namespace std;


class Solution
{
public:
	Solution(){};
	~Solution(){};
	int MyLowerBound(int a[],int n,int target)
	{
		return MyLowerBound(a,a+n,target) - a;  //!!!!
	}

	template <typename InputType,typename T>
	InputType MyLowerBound(InputType first,InputType last,T target)
	{
		while(first != last)
		{
			InputType mid = next(first,distance(first,last)/2);
			if (*mid >= target)
			{
				last = mid;
			}
			else
			{
				first = ++mid;
			}
		}
		return first;
	}
	
};


int main(int argc, char const *argv[])
{
	int a[] = {1,3,5,6};
	Solution s;
	cout << s.MyLowerBound(a,sizeof(a)/sizeof(a[0]),5) << endl;
	cout << s.MyLowerBound(a,sizeof(a)/sizeof(a[0]),2) << endl;
	cout << s.MyLowerBound(a,sizeof(a)/sizeof(a[0]),7) << endl;
	cout << s.MyLowerBound(a,sizeof(a)/sizeof(a[0]),0) << endl;
	return 0;
}