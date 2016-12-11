#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	bool isPalindrome(string str)
	{
		transform(str.begin(),str.end(),str.begin(),::tolower);
		auto beg = str.begin(),end = prev(str.end());
		while(beg < end)
		{
			while(!::isalnum(*beg))
				beg++;
			while(!::isalnum(*end))
				end--;
			if(*beg != *end)
				return false;
			beg++;
			end--;
		}
		return true;
		
	}
};

int main(int argc,char *argv[])
{
	string str = "a man,a plan,a canal: Panama";
	Solution s;
	cout << s.isPalindrome(str) << endl;
	return 0;
}
