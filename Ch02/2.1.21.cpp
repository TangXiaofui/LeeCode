#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
	vector<int> Candy(vector<int> &kids)
	{
		int n = kids.size();
		vector<int> result(n);
		int inc = 1;
		for(int i = 1; i < n;i++)
		{
			if(kids[i] > kids[i-1])
			{
				result[i] = max(inc++,result[i]);
			}
			else
				inc = 1;
		}
		inc = 1;
		for(int i = n-2; i >= 0 ; i--)
		{
			if(kids[i] > kids[i+1])
			{
				result[i] = max(inc++,result[i]);
			}
			else
				inc = 1;
		}
		
		return result;

	}
	void PrintVector(vector<int> kids)
	{
		for(auto i : kids)
			cout << i << " ";
		cout << endl;
	}
};

int main(int argc,char *argv[])
{
	vector<int> kids = {1,2,5,3,7,8,4};
	Solution s;
	s.PrintVector(kids);
	vector<int> result = s.Candy(kids);
	s.PrintVector(result);
	
	return 0;
}
