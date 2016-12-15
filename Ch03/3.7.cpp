#include <iostream>
using namespace std;

class Solution{
public:
	bool WildCardMatch(char *s,char *p)
	{
		if(*p == '*')
		{
			while(*p == '*')
				p++;
			if(*p == '\0')
				return true;
			while(*s != '\0' && !WildCardMatch(s,p))
				s++;
			return *s == *p;
		}
		else if(*s == '\0'|| *p == '\0')
		{
			return *p == *s;
		}
		else if(*s == *p || *p == '?')
		{
			return WildCardMatch(++s,++p);
		}
		else	
			return false;
	}
};

class Solution2{
public:
	bool WildCardMatch(char *s,char *p)
	{
		char *str,*ptr;
		bool star = false;
		for(str = s,ptr = p;*str != '\0' ; str++,ptr++)
		{
			switch(*ptr)
			{
				case '?':
					break;
				case '*':
					{
						star = true;
						p = ptr;
						while(*p == '*') 
							p++;
						if(*p == '\0')
							return true;
						str--;
						ptr = p-1;
					}
					break;
				default:
					{
						if(*s != *p)
						{
							if(!star)
  								return false;
							s++;
							str = s-1;
							ptr = p-1;
						}
					}
					break;
			}
		}
		while(*ptr == '*') 
			ptr++;
		if(*ptr != '\0')
			return false;
		return true;
		
	}
};
int main(int argc,char *argv[])
{
	Solution2 s;
	cout << s.WildCardMatch((char *)"aaab",(char *)"*a*b") << endl;
	return 0;
}
