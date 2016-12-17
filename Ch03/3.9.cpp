#include <iostream>
#include <algorithm>
using namespace std;

class Solution{
public:
	bool isNumber(char *s)
	{
		char *end;
		strtod(s,&end);
		if(s == end)
			return false;
		for(;*end;end++)
		{
			if(!isspace(*end))
				return false;
		}
		return true;
	}
};

int main(int argc,char* argv[])
{
	Solution s;
	cout << s.isNumber("0.1") << endl;
	return 0;
}
