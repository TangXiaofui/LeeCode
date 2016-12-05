#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	void PlusOne(vector<int> &num)
	{
		int temp = 1;
		vector<int>::reverse_iterator it;
		for(it = num.rbegin();it != num.rend();it++)
		{
			*it += temp;
			temp = *it / 10;
			*it = *it % 10;
		}
		if(temp)
		num.insert(num.begin(),temp);
	}
};

int main(int argc,char *argv[])
{
	vector<int> num = {9,9,9,9,9};
	Solution s;
	s.PlusOne(num);
	for(auto i : num)
		cout << i ;
	cout << endl;

	return 0;
}
