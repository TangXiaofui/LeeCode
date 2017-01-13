#include "13.h"
using namespace std;

class Solution
{
public:
	Solution() {};
	~Solution() {};
	bool isInterleavingString(string &s1, string &s2, string &s3)
	{
		if (s1.size() + s2.size() != s3.size())
		{
			return false;
		}
		return isInterleavingString(begin(s1), end(s1), begin(s2), end(s2), begin(s3), end(s3));
	}
	template <typename Input>
	bool isInterleavingString(Input s1b, Input s1e, Input s2b, Input s2e, Input s3b, Input s3e)
	{
		if (s3b == s3e)
		{
			return s1b == s1e && s2b == s2e;
		}

		return (*s1b == *s3b && isInterleavingString(next(s1b), s1e, s2b, s2e, next(s3b), s3e))
		       || (*s2b == *s3b && isInterleavingString(s1b, s1e, next(s2b), s2e, next(s3b), s3e));

	}
};

class Solution2
{
public:
	Solution2(){};
	~Solution2(){};
	bool isInterleavingString(string s1,string s2,string s3)
	{
		if (s1.length() + s2.length() != s3.length())
		{
			return false;
		}

		std::vector<std::vector<bool>> f(s1.length()+1,std::vector<bool>(s2.length()+1,true));
		for (int i = 1; i <= s1.length(); ++i)
		{
			f[i][0] = f[i-1][0] && s1[i-1] == s3[i-1];
		}

		for (int i = 1; i <= s2.length(); ++i)
		{
			f[0][i] = f[0][i-1] && s2[i-1] == s3[i-1];
		}
		for (int i = 1; i <= s1.length(); ++i)
		{
			for (int j = 1; j <= s2.length(); ++j)
			{
				f[i][j] = (s1[i-1] == s3[i+j-1] && f[i-1][j] ) || (s2[j-1] ==s3[i+j-1] && f[i][j-1] );
			}
		}
		return f[s1.length()][s2.length()];
	}
	
};

int main(int argc, char const *argv[])
{
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbcbcac";
	string s4 = "aadbbbaccc";
	Solution s;
	cout << s.isInterleavingString(s1, s2, s3) << endl;
	cout << s.isInterleavingString(s1, s2, s4) << endl;

	bool tmp = 1 == 2 && 1;
	cout << tmp << endl;

	tmp = 1 && 2 == 1;					// == 优先级大于 &&
	cout << tmp << endl;

	cout << "--------------" << endl;
	Solution2 ss;
	cout << ss.isInterleavingString(s1,s2,s3) << endl;
	cout << ss.isInterleavingString(s1,s2,s4) << endl;

	return 0;
}