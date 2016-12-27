#include "../8.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<int>> subsets(std::vector<int> v)
	{
		sort(v.begin(),v.end());   //!!!!!!!!!
		std::vector<std::vector<int>> result;
		std::vector<int> path;
		subsets(v,path,0,result);
		return result;
	}

	void subsets(std::vector<int> S,std::vector<int> &path,int step,std::vector<std::vector<int> > &result)
	{
		if (step == (int)S.size())
		{
			result.push_back(path);
			return ;
		}

		subsets(S,path,step+1,result);
		path.push_back(S[step]);
		subsets(S,path,step+1,result);
		path.pop_back();
	}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {1,2,3};
	Solution s;
	auto res = s.subsets(v);
	for(auto r:res)
	{
		for(auto i : r)
		{
			cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}