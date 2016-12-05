#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution{
public:
	int LongestConsecutive(vector<int> &nums)
	{
		map<int,bool> used;
		int longest = 0;
		for(auto num : nums)
		{
			used[num] = false;
		}
		
		for(auto num : nums)
		{
			if(used[num])
				continue;
			int len = 1;
			for(auto temp = num + 1 ; used.find(temp) != used.end();temp++)
			{
				used[temp] = true;
				len++;
			}
			for(auto temp = num - 1; used.find(temp) != used.end();temp-- )
			{
				used[temp] = true;
				len++;
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
	vector<int> nums = {100,2,4,200,3,1,5};
	Solution s;
	cout << s.LongestConsecutive(nums) << endl;
	
	return 0;
}
