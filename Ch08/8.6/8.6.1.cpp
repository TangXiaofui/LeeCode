#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	const vector<string> keyboard { " ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	std::vector<string> letterCombinations(string strNum)
	{
		std::vector<string> result;
		string s;

		dfs(strNum,0,s,result);
		return result;
	}
	void dfs(const string &strNum,int pos,string s,std::vector<string> &result)
	{
		if (strNum.size() == s.size())
		{
			result.push_back(s);
			return ;
		}

		for(auto i:keyboard[strNum[pos]-'0'])
		{
			dfs(strNum,pos+1,s+i,result);
		}
	}
};

int main(int argc, char const *argv[])
{
	string strNum = "23";
	std::vector<string> result;
	Solution s;
	result = s.letterCombinations(strNum);
	for(auto e : result)
		cout << e << endl;
	return 0;
}