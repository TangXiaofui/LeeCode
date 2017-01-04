#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<string>> SolvedNQueen(int n)
	{
		std::vector<std::vector<string>> result;
		std::vector<int> path(n,0);

		diag_col.resize(2*n,0);
		cor_col.resize(2*n,0);
		colume.resize(n,0);

		dfs(n,0,path,result);
		return result;	
	}
	void dfs(int n,int step,std::vector<int> &path,std::vector<std::vector<string>> &result)
	{
		if (step == n)
		{
			std::vector<string> res;
			for(auto p : path)
			{
				string tmp;
				for (int i = 0; i < n; ++i)
				{
					if (p == i)
					{
						tmp += 'Q';

					}
					else
						tmp += '.';
				}
				res.push_back(tmp);
			}
			result.push_back(res);
			return ;
		}
		for (int i = 0; i < n; ++i)
		 {
		 	bool ok = colume[i] == 0 && diag_col[step + i] == 0 && cor_col[step - i + n ] == 0;
		 	if (ok)
		 	{
		 		path[step] = i;
		 		colume[i] = 1;
		 		diag_col[step + i] = 1;
		 		cor_col[step - i + n] = 1;
		 		dfs(n,step + 1,path,result);

		 		colume[i] = 0;
		 		diag_col[step + i] = 0;
		 		cor_col[step - i + n] = 0;
		 	}
		 } 
	}
private:
	std::vector<int> colume;
	std::vector<int> diag_col;
	std::vector<int> cor_col;	
};

int main(int argc, char const *argv[])
{
	Solution s;
	auto result = s.SolvedNQueen(4);
	for(auto res : result)
	{
		for(auto str : res)
		{
			cout << str << endl;
		}
		cout << endl;
	}
	return 0;
}