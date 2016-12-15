#include <iostream>
#include <string.h>
using namespace std;


class Solution{
public:
	char *strStr(char *haystack ,char *pattern)
	{
		int pos = kmp(haystack,pattern);
		if(pos == -1)
			return NULL;
		else
			return (char *)haystack+pos;
	}
	void compute_prefix(char *pattern,int next[])
	{
		int n = strlen(pattern);
		int j = -1;
		next[0] = j;
		for(int i = 1 ; i < n; i++)
		{
			while(j > -1 && pattern[j+1] != pattern[i])
				j = next[j];
			if(pattern[j+1] == pattern[i])
			{
				j++;
			}
			next[i] = j;
		}
	}

	int kmp(char *haystack,char *pattern)
	{
		int m = strlen(haystack);
		int n = strlen(pattern);	
		if(m == 0 || n == 0)
			return -1;
		int *next = new int(n*sizeof(int));
		compute_prefix(pattern,next);
		for( int i = 0; i < n ; i++)
			cout << next[i] << " ";
		cout << endl;
		int j = -1;
		for(int i = 0; i < m ;i++)
		{
			while(j > -1 && pattern[j+1] != haystack[i])
				j = next[j];
			if(pattern[j+1] == haystack[i])
			{
				j++;
				if(j == n-1)
					return i-j;
			}
		}
		delete[] next;
		return -1;
	}

};


int main(int argc, char *argv[])
{
    char *haystack = (char *) "BBC ABCDAB ABCDABCDABDE";
    char *needle = (char *) "ABCDABD";
	cout << haystack << endl;
    Solution s;
    cout << s.strStr(haystack, needle) << endl;

    return 0;
}
