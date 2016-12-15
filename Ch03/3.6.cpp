#include <iostream>
using namespace std;

class Solution{
public:
	bool isMatch(char *s,char *p)
	{
		if(*p == '\0')
			return *s == '\0';
		if(*(p+1) != '*')
		{
			if(*p == *s || (*p == '.'&& *p != '\0'))
			{
				return isMatch(s+1,p+1);
			}
			else
				return false;	
		}
		else
		{
			while(*s == *p || (*p == '.' && *p != '\0'))
			{
				if(isMatch(s,p+2))
					return true;
				s++;
			}
			return isMatch(s,p+2);
		}
	}
};

int main(int argc,char *argv[])
{

	Solution s;
	cout << s.isMatch((char*)"aab",(char*)"c*a*b") << endl;
	return 0;
}
