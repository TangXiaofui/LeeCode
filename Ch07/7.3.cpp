#include "7.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool SearchMatrix(std::vector<std::vector<int>> v,int target)
	{
		int m = v.size();
		int n = v.front().size();
		int first = 0;
		int last = m*n;
		while(first != last)
		{
			int mid = first + ( last - first )/2;
			int value = v[mid/n][mid%n];
			if (value == target)
			 {
			 	return true;
			 } 
			 else if(value > target)
			 {
			 	last = mid;
			 }
			 else
			 	first = mid+1;
		}
		return false;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<int>> v = {
		{1,3,5,7},
		{10,11,16,20},
		{23,30,34,50}
	};
	Solution s;
	cout << s.SearchMatrix(v,3) << endl;
	return 0;
}
