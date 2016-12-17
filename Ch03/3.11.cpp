#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
	int map(const char c)
	{
		switch(c){
			case 'I' : return 1;
			case 'V' : return 5;
			case 'X' : return 10;
			case 'L' : return 50;	//!!
			case 'C' : return 100;
			case 'D' : return 500;
			case 'M' : return 1000;
			defualt: return 0;       //!!!!
		}
	}
	int RomanToInteger(string Roman)
	{
		int num = 0; 
		for(int i = 0 ; i < Roman.size();i++)
		{
			if(i > 0 && map(Roman[i]) > map(Roman[i-1]))
			{
				num = num + map(Roman[i]) - 2 * map(Roman[i-1]); //!!
			}
			else
				num = num + map(Roman[i]);
		}
		return num;
	}
};

int main(int argc,char *argv[])
{
	Solution s;
	cout << s.RomanToInteger("CCCXCIX") << endl;
	return 0;
}
