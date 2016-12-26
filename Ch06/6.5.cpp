#include "6.h"

class Solution
{
public:
	Solution(){};
	~Solution(){};

	void SortColor(int a[],int n)
	{
		int count[3] = {0};
		for (int i = 0; i < n; ++i)
		{
			count[a[i]]++;
		}
		int cur = 0;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < count[i]; ++j)
			{
				a[cur++] = i;
			}
		}
	}
	
};

class Solution2
{
public:
	Solution2(){};
	~Solution2(){};
	void SortColor(int a[],int n)
	{
		int red = 0,blue = n-1;
		for (int i = 0; i < blue+1 ;)  // < blue+1
		{
			if (a[i] == 0)
			{
				swap(a[red++],a[i++]); //i++
			}
			else if (a[i] == 2)
			{
				swap(a[i],a[blue--]);
			}
			else
			{
				i++;
			}
		}
	}
	
};

class Solution3
{
public:
	Solution3(){};
	~Solution3(){};
	void SortColor(int a[],int n)
	{
		partition(partition(a,a+n,bind1st(equal_to<int>(),0)),a+n,bind1st(equal_to<int>(),1));
	}
	
};

class Solution4
{
public:
	Solution4(){};
	~Solution4(){};
	void SortColor(int a[],int n)
	{
		partition1(partition1(a,a+n,bind1st(equal_to<int>(),0)),a+n,bind1st(equal_to<int>(),1));
	}
	template<typename InputType,typename FUNC>
	InputType partition1(InputType first,InputType last,FUNC pred)
	{
		InputType pos = first;
		for(;first != last;++first)
		{
			if (pred(*first))
			{
				swap(*first,*pos++);
			}
		}
	}

	
};

int main(int argc, char const *argv[])
{
	int a[] = {2,1,0,1,2,0,2,1,1,0};
	Solution4 s;
	s.SortColor(a,sizeof(a)/sizeof(a[0]));
	for(auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}