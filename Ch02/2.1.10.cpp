#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	int RemoveElem(int a[],int len,int elem)
	{
		int index = 0;
		for(int i = 0; i < len ; i++)
			if(a[i] != elem)
				a[index++] = a[i];
		return index;

	}
	
	int RemoveElem2(int a[],int len,int elem)
	{
		return distance(a,remove(a,a+len,elem));
	}
	
	void printArray(int a[],int len)
	{
		for(int i = 0 ; i < len ; i++)
		{
			cout << a[i] << " "; 
		}
		cout << endl;
	}
};

int main(int argc,char *argv[])
{
	int nums[] = {1,2,3,4,5,4,3,2,6,7,8,4};
	int len = sizeof(nums) / sizeof(nums[0]);
		
	Solution s;
	int ret;
	ret = s.RemoveElem2(nums,len,4);
	s.printArray(nums,ret);
	
	return 0;
}
