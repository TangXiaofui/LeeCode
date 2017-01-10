#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int LongestSubset(string s)
	{
		const int ASCIILEN = 26;
		int last[ASCIILEN];
		fill(last,last+ASCIILEN,-1);
		int n = s.size();
		int len = 0;
		int max_len = 0;
		for (int i = 0; i < n; ++i,++len)
		{
			if (last[s[i] - 'a'] >= 0)
			{
				max_len = max(len,max_len);
				i = last[s[i] - 'a']+1;
				len = 0;
				fill(last,last+ASCIILEN,-1);
			}
			last[s[i] - 'a'] = i;
		}
		return max(max_len,len);
	}
	
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.LongestSubset("qpxrjxkltzyx") << endl;
	return 0;
}