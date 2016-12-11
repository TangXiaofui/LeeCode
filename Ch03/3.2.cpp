#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Solution {
  public:
    char *strStr(const char *haystack, const char *needle) {
	if (needle == NULL)
	    return (char *) haystack;
	char *p1_advance = (char *) haystack;
	char *p2 = (char *) needle;
	for (char *tmp = (char *)&needle[1]; *tmp; p1_advance++) {
	    tmp++;
	} for (char *p1 = (char *)haystack; *p1_advance; p1_advance++) {
	    char *p1_old = p1;
	    p2 = (char *) needle;
	    while (*p2++ == *p1++);

	    if (!*p2)
		return p1_old;
	    p1 = p1_old + 1;
	}
	return NULL;
    }
};

class Solution2 {
  public:
    char *strStr(char *text, char *pattem) {
	int pos = kmp(text, pattem);
	if (pos == -1)
	    return NULL;
	else
	     return (char *) text + pos;
    } void compute_prefix(char *pattem, int next[]) {
	int j = -1;
	next[0] = j;
	int n = strlen(pattem);
	for (int i = 1; i < n; i++) {
	    while (j > -1 && pattem[j + 1] != pattem[i])
		j = next[j];

	    if (pattem[j + 1] == pattem[i])
		j++;
	    next[i] = j;
	}
    }

    int kmp(char *text, char *pattem) {
	int m = strlen(text);
	int n = strlen(pattem);
	if (m == 0 || n == 0)
	    return -1;
	int *next = (int *) malloc(sizeof(int) * n);
	compute_prefix(pattem, next);
	for (int i = 0; i < n; i++)
	    cout << next[i] << " ";
	cout << endl;
	int j = -1;
	for (int i = 0; i < m; i++) {
	    while (j > -1 && text[i] != pattem[j + 1])
		j = next[j];

	    if (pattem[j + 1] == text[i]) {
		j++;
		if (j == n - 1) {
		    return i - j;
		}
	    }

	}
	free(next);
	return -1;
    }

};


class Solution3{
public:
	char *strStr(char *text,char *pattern)
	{
		int pos = kmp(text,pattern);
		if(pos == -1)
			return NULL;
		else
			return (char*)text+pos;
		
	}
	void compute_prefix(char *pattern,int next[])
	{
		int j = -1;
		next[0] = j;
		int n = strlen(pattern);
		for(int i = 1; i < n ; i++)
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
	int kmp(char *text,char *pattern)
	{
		int m = strlen(text);
		int n = strlen(pattern);
		if(m == 0 || n == 0)
		{
			return -1;
		}
		
		int *next = new int(n*sizeof(int));
		compute_prefix(pattern,next);
		for (int i = 0; i < n; i++)
	    	cout << next[i] << " ";
		cout << endl;
		int j = -1;
		for(int i = 0 ; i < m;i++ )
		{
			while(j > -1 && pattern[j+1] != text[i])
				j = next[j];

			if(text[i] == pattern[j+1])
			{
				j++;
				if(j == n - 1)
				return i - j;
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
    Solution3 s;
    cout << s.strStr(haystack, needle) << endl;

    return 0;
}
