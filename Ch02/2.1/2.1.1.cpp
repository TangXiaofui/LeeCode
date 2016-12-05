#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	int RemoveDuplicate(int a[],int len)
	{
		int index = 0;
		for(int i = 0; i < len; i++)
		{
			if(a[index] != a[i])
				a[++index] = a[i];	
		
		}
		return index+ 1;
	}
	void PrintArray(int a[],int len)
	{
		for(int i = 0 ; i < len; i++)
		{
			cout << a[i] << " " ;
		}
		cout << endl;
	}
};

class Solution2{
public:
        int RemoveDuplicate(int a[],int len)
        {
                return distance(a,unique(a,a+len));
        }
        void PrintArray(int a[],int len)
        {
                for(int i = 0 ; i < len; i++)
                {
                        cout << a[i] << " " ;
                }
                cout << endl;
        }
};

class Solution3{
public:
        int RemoveDuplicate(int a[],int len)
        {
		return tempRemoveDuplicate(a,a+len,a) - a;
        }
	template<typename InIt,typename OutIt>
	OutIt tempRemoveDuplicate(InIt first,InIt last,OutIt output)
	{
		while(first != last)
		{
			*output++ = *first;
			first = find_if(first,last,bind1st(not_equal_to<int>(),*first));
		}
		return output;
	}

        void PrintArray(int a[],int len)
        {
                for(int i = 0 ; i < len; i++)
                {
                        cout << a[i] << " " ;
                }
                cout << endl;
        }
};


int main(int argc,char *argv[])
{
	int a[] = {1,1,2,2,2,3,3,3,4,4,4,4,4};
	int len = sizeof(a)/sizeof(a[0]);
	Solution3 s;
	s.PrintArray(a,s.RemoveDuplicate(a,len));	
}
