#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	int RemoveDuplicate(int a[],int len)
	{
		int index = 0;
		int Count = 0;
		for(int i = 0 ; i < len ; i++)
		{
			if(a[index] != a[i])
			{
				Count = 0;
				a[++index] = a[i];
			}
			else
			{
				if(Count < 1)
				{
					Count++;
					a[++index] = a[i];
				}
			}
		}
		return index + 1;
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
		int index = 0;
		for(int i = 0 ; i < len ;i++)
		{
			if(  i > 0 && i < len-1 && a[i-1] == a[i] && a[i] == a[i+1] )
				continue;
			a[index++] = a[i];
		}
		return index + 1;
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
	Solution2 s;
	s.PrintArray(a,s.RemoveDuplicate(a,len));	
}
