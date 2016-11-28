#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int trapWater(int a[],int len)
	{
		int MaxIndex= 0;
		int Max = 0;
		for(int i = 0 ; i < len ; i++)
		{
			if(a[i] > Max)
			{
				Max = a[i];
				MaxIndex = i;
			}
		}
		
		int area = 0;
		int root = a[0];
		for(int i = 0 ; i < MaxIndex ;i++)
		{
			if(root < a[i])
				root = a[i];
			else
				area += (root - a[i]);
		}
		
		root = a[len-1];
		for(int i = len -1 ; i > MaxIndex;i--)
		{
			if(root < a[i])
				root = a[i];
			else
				area += (root - a[i]);
		}
		return area;
	}
};

int main(int argc,char*argv[])
{
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	int len = sizeof(a) / sizeof(a[0]);
	Solution s;
	cout <<	s.trapWater(a,len) << endl;
	return 0;
}
