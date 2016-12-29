#include "../8.h"
using namespace std;


class Solution
{
public:
	Solution(){};
	~Solution(){};
	const vector<string> keyboard { " ", "", "abc", "def", // '0','1','2',...
"ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	vector<string> letterCombinations (const string &digits) 
	{
		std::vector<string> result(1,"");
		for(auto d:digits)
		{
			int n = result.size();
			int m = keyboard[d-'0'].size();
			result.resize(n*m);
			for (int i = 0; i < m; ++i)
			{
				copy(result.begin(), result.begin()+n,result.begin()+i*n);
			}

			for (int i = 0; i < m; ++i)
			{
				auto begin = result.begin();
				for_each(begin+i*n,begin+(i+1)*n,[&](string &s){
					s += keyboard[d-'0'][i];
				});
			}
		}
		return result;
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