#include "9.h"
using namespace std;
class Solution
{
public:
	Solution(){};
	~Solution(){};
	int WordLadder(string start,string end, std::unordered_set<string> &dict)
	{
		if (start.size() != end.size())
		{
			return -1;
		}
		if (start.size() == 0)
		{
			return 0;
		}
		if (start == end)
		{
			return 0;
		}
		int level = 0;
		queue<string> cur,next;
		unordered_set<string> visit;
		bool found = false;
		cur.push(start);
		while(!cur.empty() && !found)
		{
			level++;
			while(!cur.empty() && !found)
			{
				string str = cur.front();
				cur.pop();
				int len = str.size();
				for (int i = 0; i < len; ++i)
				{
					string newStr(str);
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
							break;
						}
						if (visit.count(newStr) == 0 && dict.count(newStr) > 0)
						{
							next.push(newStr);
							visit.insert(newStr);
						}
						swap(newStr[i],j);
					}
				}
			}
			swap(cur,next);
		}
		if (found)
		{
			return level;
		}
		else
			return -1;
	}
};


int main(int argc, char const *argv[])
{
	std::unordered_set<string> dict = {"hot","dot","dog","lot","log"};
	string start = "hit";
	string end = "cog";
	Solution s;
	cout << s.WordLadder(start,end,dict) << endl;

	return 0;
}