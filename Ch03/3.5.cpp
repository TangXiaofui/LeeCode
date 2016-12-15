#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string preProcess(string s)
	{
		string T = "^#";
		for(auto e:s)
			T = T+e+"#";
		T += "$";
		return T;
	}
	string LongestPalindrome(string s)
	{
		string T = preProcess(s);
		int C = 0;
		int R = 0;
		const int n = T.size();
		int P[n];
		for(int i = 1 ; i < n - 1; i++ )
		{
			int i_mirror = 2*C -i;
			
			P[i] = R > i ? min(R-i,P[i_mirror]):0;
			
			while(T[i+1+P[i]] == T[i - 1 - P[i]])
				P[i]++;
			
			if(i+P[i] > R)
			{
				C = i;
				R = i + P[i];
			}
		}

		int max_len = 0;
		int pos = 0;
		for(int i = 1; i < n - 1 ;i++ )
		{
			if(P[i] > max_len)
			{
				pos = i;
				max_len = P[i];
			}
		}
		
		return s.substr((pos-max_len-1)/2,max_len);
		
		return T;
	}
};

int main(int argc,char *argv[])
{
	Solution s;
	cout << s.LongestPalindrome("babcbabcbaccba") << endl;
	return 0;
}
