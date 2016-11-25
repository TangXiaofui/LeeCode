#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	int LongestConsecutive(vector<int> &nums)
	{
		int longest = 0;
		map<int,bool> used;
		for(auto num : nums)
			used[num] = false;

		for(auto num:nums)
		{
			int len = 1;
			if(used[num])
				continue;

			for(auto tmp = num + 1 ; used.find(tmp) != used.end(); tmp++ )
			{
				used[tmp] = true;
				len++;
			}
			for(auto tmp = num - 1 ; used.find(tmp)!= used.end();tmp-- )
			{
				used[tmp] = true;
				len++
			}
			
			if(len > longest)
			{
				longest = len;
			}
		}		
		return longest;
	}
};


int main(int argc,char *argv[])
{
	vector<int> nums = {100,2,4,200,3,1};
	Solution s;
	cout << s.LongestConsecutive(nums) << endl;
	
	return 0;
}
