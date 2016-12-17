#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution{
public:
	string LongestCommonPrefix(vector<string> &strs)
	{
		for(int i = 0 ; i < strs[0].size(); i++)
		{
			for(int j = 1 ; j < strs.size();j++)
			{
				if(strs[j][i] != strs[0][i])
					return strs[0].substr(0,i);
			}
		}
		return strs[0];
	}
};

class Solution2{
public:
	string LongestCommonPrefix(vector<string> &strs)
	{
		int len = strs[0].size();
		for(int i = 1 ; i < strs.size();i++)
		{
			for(int j = 0; j < len;j++)
			{
				if(strs[i][j] != strs[0][j])
					len = j;
			}
		}
		return strs[0].substr(0,len);
	}
};

int main(int argc,char *argv[])
{
	vector<string> strs = {"abcd","abcdef","abc","ab"};
	Solution s;
	cout << s.LongestCommonPrefix(strs) << endl;
	Solution2 ss;
	cout << ss.LongestCommonPrefix(strs) << endl;
	return 0;
}
