#include "6.h"


class Solution
{
public:
	Solution(){};
	~Solution(){};
	int FirstMissingPosition(int a[],int n)
	{
		bucket_sort(a,n);
		for (int i = 0; i < n; ++i)
		{
			if (a[i] != i+1)
			{
				return i+1;
			}
		}
		return n+1;
	}
	void bucket_sort(int a[],int n)
	{
		for (int i = 0; i < n; ++i)
		{
			while(a[i] != i+1)		//!!!!!!!!!!!!!!!!
			{
				if (a[i] <= 0 || a[i] > n || a[i] == a[a[i]-1])
				{
					break;
				}
					swap(a[i],a[a[i] - 1]);
			}
			
		}
	}
	
};

int main(int argc, char const *argv[])
{
	int a[] = {1,2,0};
	Solution s;
	cout << s.FirstMissingPosition(a,sizeof(a)/sizeof(a[0])) << endl;
	int b[] = {3,4,-1,1};
	cout << s.FirstMissingPosition(b,sizeof(b)/sizeof(b[0])) << endl;
	return 0;
}