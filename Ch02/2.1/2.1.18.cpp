#include <iostream>
#include <vector>
using namespace std;


class Solution{
public:
	vector<int> GrayCode(int num)
	{
		vector<int> result;
		for(int i = 0; i < num ;i++ )
			result.push_back(binary_to_gray(i));
		return result;
	}
	vector<int> GrayCode2(int num)
	{
		vector<int> result;
		result.push_back(0);
		for(int i = 0; i < num ; i++)
		{
			for(int j = result.size()-1; j >= 0 ;j-- )
				result.push_back( result[j] | 1 << i);
		}
		return result;
	}
	int binary_to_gray(int n)
	{
		return n^(n>>1);
	}
};

int main(int argc,char *argv[])
{
	Solution s;
	vector<int> tmp = s.GrayCode2(3);
	for(auto t:tmp)
		cout << t << " ";
	cout << endl;
	return 0;
}
