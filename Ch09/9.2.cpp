#include "9.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<std::vector<string>> WordLadderII(string start,string end,unordered_set<string> &dict)
	{
		unordered_set<string> visit;
		unordered_set<string> cur,next;
		unordered_map<string,std::vector<string>> father;
		cur.insert(start);
		bool found = false;
		while(!cur.empty() && !found)
		{
			for(auto elem:cur)
				visit.insert(elem);
			for(auto elem:cur)
			{
				int len = elem.size();
				string newStr(elem);
				for (int i = 0; i < len; ++i)
				{
					for (char j = 'a'; j <= 'z'; ++j)
					{
						if (newStr[i] == j)
						{
							continue;
						}
						swap(newStr[i],j);
						if (newStr == end)
						{
							found = true;
						}
						if (visit.count(newStr) == 0 &&(dict.count(newStr) > 0 || found))   //!!!!字典可能不存在该词
						{
							next.insert(newStr);
							father[newStr].push_back(elem);
						}
						swap(newStr[i],j);
					}
				}
			}
			cur.clear();
			swap(cur,next);
		}
		std::vector<std::vector<string>> result;
		std::vector<string> path;
		if (found)
		{
			BuildTree(father,start,end,path,result);
		}

		return result;
	}
	void BuildTree(unordered_map<string,std::vector<string>> &father,string &start,string &end,std::vector<string> &path,
		std::vector<std::vector<string>> &result)
	{
		path.push_back(end);
		if (start == end)
		{
			result.push_back(path);
			reverse(result.back().begin(),result.back().end());
		}
		else
		{
			for(auto elem : father[end])
			{
				BuildTree(father,start,elem,path,result);
			}
		}
		path.pop_back();

	}
};

int main(int argc, char const *argv[])
{
	std::unordered_set<string> dict = {"hot","dot","dog","lot","log"};
	string start = "hit";
	string end = "cog";
	Solution s;
	auto result = s.WordLadderII(start,end,dict);
	for(auto res :result)
	{
		for(auto elem : res)
		{
			cout << elem << " " ;
		}
		cout << endl;
	}

	return 0;
}