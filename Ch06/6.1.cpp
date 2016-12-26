#include "6.h"


class Solution
{
public:
	Solution(){};
	~Solution(){};

	void MergeTwoArray(int a[],int ia,int b[],int ib)
	{
		int cur = ia+ib-1;
		ia--;
		ib--;
		for(; ia >= 0 && ib >= 0;)
		{
			a[cur--] = a[ia] > b[ib] ? a[ia--] :b[ib--];
		}
		while(ib >= 0)
			a[cur--] = b[ib--];
	}
};

int main(int argc, char const *argv[])
{
	int a[10] = {1,3,5,7,9};
	int b[] = {2,4,6,8};

	Solution s;
	s.MergeTwoArray(a,5,b,sizeof(b)/sizeof(b[0]));
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}