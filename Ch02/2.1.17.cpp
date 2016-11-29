#include <iostream>
using namespace std;

class Solution{
public:
	int climbingStair(int n )
	{
		int i = 0; 
		int first = 1;
		int second = 0;
		int temp;
		while(i < n)
		{
			temp = first;
			first += second;
			second = temp;
			i++;
		}
		return first;
	}
};


int main(int argc,char *argv[])
{
	Solution s;
	for(int i = 1 ; i < 6 ; i++)
	{
	 	cout << s.climbingStair(i) << " ";
	}	
	cout << endl;
	return 0;

}
