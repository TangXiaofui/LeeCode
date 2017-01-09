#include "11.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	double pow(double x, int n)
	{
		if (n < 0)
		{
			return 1 / power(x,-n);
		}
		return power(x,n);
	}
	double power(double x,int n)
	{
		if (n == 0)
		{
			return 1;
		}
		double v = power(x,n/2);
		if (n % 2)
		{
			return v * v * x;
		}
		return v*v;
	}
	
};
int main(int argc, char const *argv[])
{
	Solution s;
	cout  << s.pow(5,3) << endl;
	return 0;
}