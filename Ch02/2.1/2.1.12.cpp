#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution{
public:
	string GetPermutation(int n,int k)
	{
		string s(n,'0');
		for(int i = 0 ; i < n; i++)
			s[i] += i+1;
		return find_kthPermutation(s,k);
	}
	int factorial(int n)
	{
		int sum = 1;
		for(int i = 1; i <= n; i++)
			sum *= i;
		return sum;
	}
	template<typename Seque>
	Seque find_kthPermutation(const Seque &s,int k)
	{
		Seque temp(s);
		Seque result;
		int n = s.size();
		int base = factorial(n-1);
		k--;
		for(int i = n-1; i > 0 ; k %= base,base /= i,i--)
		{
			auto pos = next(temp.begin(),k / base);
			result.push_back(*pos);
			temp.erase(pos);
		}
		result.push_back(temp[0]);
		return result;
	}

	
};

int main(int argc,char *argv[])
{
	Solution s;
	string result = s.GetPermutation(5,3);
	for(auto it : result)
		cout << it << " ";
	cout << endl;
	return 0;
}
