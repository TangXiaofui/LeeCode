#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool isParlindrome(string &s,int start,int end)
	{
		while(start < end)
		{
			if (s[start] != s[end])
			{
				return false;
			}
			start++;
			end--;
		}
		return true;
	}

	std::vector<std::vector<string>> partition(string &s)
	{
		std::vector<std::vector<string>> result;
		std::vector<string> path;
		dfs(s,0,path,result);
		return result;
	}

	void dfs(string &s, int start, std::vector<string> &path,std::vector<std::vector<string>> &result)
	{
		if (start == (int)s.size())
		{
			result.push_back(path);
			return ;
		}
		for (int i = start; i < (int)s.size(); ++i)
		{
			if (isParlindrome(s,start,i))
			{
				path.push_back(s.substr(start,i-start+1));
				dfs(s,i+1,path,result);
				path.pop_back();
			}
		}
	}

};

int main(int argc, char const *argv[])
{
	string str = "aabaa";
	Solution s;
	auto result = s.partition(str);
	PrintElem(result);
	return 0;
}

