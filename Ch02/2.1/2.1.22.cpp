#include <iostream>
#include <vector>
using namespace std;
class Solution{
public:
	int SingleNumber2(vector<int> nums)
	{
		int temp = 0;
		for(auto num : nums)
			temp ^= num;
		return temp;		
	}
	int SingleNumber3(vector<int> nums)
	{
		const int W = sizeof(int)*8;
		int count[W];
		fill_n(count,W,0);
		for(int i = 0 ; i < nums.size();i++)
		{
			for(int j = 0; j < W ; j++)
			{
				count[j] += nums[i] >> j & 1;
				count[j] %=3;
			}
		}
		int temp = 0;
		for(int i = 0 ; i < W ;i++)
		{
			if(count[i])
			temp += count[i]<<i;
		}
		return temp;

	}
};

int main(int argc,char *argv[])
{
	vector<int> nums2 = {1,1,2,2,3,3,4,5,5,6,6};
	vector<int> nums3 = {1,1,1,2,2,2,3,4,4,4};
	Solution s;
	cout << s.SingleNumber2(nums2) << endl;
	cout << s.SingleNumber3(nums3) << endl;
	return 0;
}
