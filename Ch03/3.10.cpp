#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	string IntegerToRoman(int num)
	{
		const int radix[] = {1000, 900, 500, 400, 100, 90,50, 40, 10, 9, 5, 4, 1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC","L", "XL", "X", "IX", "V", "IV", "I"};
		string roman;
		for(int i = 0 ;num > 0; i++)
		{
			int count = num / radix[i];
			num = num % radix[i];
			for(int j = 0 ; j < count ;j++ )
				roman += symbol[i];
		}
		return roman;
	}
};

int main(int argc,char *argv[])
{
	Solution s;
	cout << s.IntegerToRoman(3) << endl;
	return 0;
}
