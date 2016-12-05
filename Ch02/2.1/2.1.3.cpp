#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	int Search(int a[],int len ,int elem)
	{
	        int left = 0; 
		int right = len -1; 
		while(left <= right)
		{
			int mid = (left + right)/2;
			if(a[mid] == elem)
			{
				return mid;
			}
			if(a[left] <= a[mid])
			{
				if(elem >= a[left] && elem < a[mid])
				{
					right = mid -1;
				}
				else 
				{
					left = mid+1;
				}
			}
			else
			{
				if(elem > a[mid] && elem <= a[right])
					left = mid + 1;
				else
					right = mid;
			}
		}
		return -1;
	}
	int SearchDup(int a[],int len ,int elem)
        {
                int left = 0;
                int right = len -1;
                while(left <= right)
                {
                        int mid = (left + right)/2;
                        if(a[mid] == elem)
                        {
                                return mid;
                        }
                        if(a[left] < a[mid])
                        {
                                if(elem >= a[left] && elem < a[mid])
                                {
                                        right = mid - 1;
                                }
                                else
                                {
                                        left = mid;
                                }
                        }
                        else if(a[left] > a[mid])
                        {
                                if(elem >= a[mid] && elem <= a[right])
                                        left = mid;
                                else
                                        right = mid;
                        }
			else
			{
				left++;
			}
                }
                return -1;
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
	int a[] = {4,5,6,7,0,1,2};
	int b[] = {1,3,1,1,1};
	int len = sizeof(a)/sizeof(a[0]);
	Solution s;
	cout << s.Search(a,len,2) << endl;
	cout << s.SearchDup(b,5,3) << endl;
}
