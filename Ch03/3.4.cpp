#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
	string AddBinary(string a,string b)
	{
		string result;
		int n = a.size() > b.size() ? a.size(): b.size();
		int carry = 0;
		reverse(a.begin(),a.end());
		reverse(b.begin(),b.end());
		for(int i = 0 ; i < n ; i++)
		{
			int ai = a.size() > i ? a[i] - '0': 0 ;
			int bi = b.size() > i ? b[i] - '0': 0 ;
			int tmp = (ai+bi+carry)%2;
			carry = (ai+bi+carry)/2;
			result.insert(result.begin(),'0'+tmp);
		}
		if(carry)
			result.insert(result.begin(),'1');
		return result;
	}
};


int main(int argc,char *argv[])
{
	string a = "111";
	string b = "10";
	Solution s;
	cout << s.AddBinary(a,b) << endl;
}
