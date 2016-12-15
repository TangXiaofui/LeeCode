#include <iostream>
#include <climits>
using namespace std;
class Solution{
public:
	int atoi(char *num)
	{
		int sum = 0 ;
		int sign = 0;
		while(*num == ' ')
			num++;
		while(*num == '+' || *num == '-')
			if(*num++ == '+')
				sign = 1;
			else
				sign = -1;

		while(*num)
		{
			if(*num < '0' || *num > '9')
				break;
			if(sum > INT_MAX / 10 || sum == INT_MAX/10  && *num > INT_MAX % 10)
			{
				return sign == -1 ? INT_MIN*sign:INT_MAX;
			}
			sum = sum * 10 + *num-'0';
			num++;
		}
		return sign*sum;
	}
};

int main(int argc,char *argv[])
{
	Solution s;
	cout << s.atoi(argv[1]) << endl;

}
