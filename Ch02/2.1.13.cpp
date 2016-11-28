#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution{
public:
	bool isValidSodu(vector<vector<char>> &sodu)
	{
		bool used[9];
		for(int i = 0; i < 9 ; i++)
		{
			fill(used,used+9,false);
			for(int j = 0 ; j < 9 ;j++)
			{
				if(!check(sodu[i][j],used))
					return false;
			}
			fill(used,used+9,false);
			for(int j = 0 ; j < 9;j++)
			{
				if(!check(sodu[j][i],used))
					return false;
			}
		}
		for(int r = 0 ; r < 3; r++)
			for(int c = 0 ; c < 3; c++)
		{
			fill(used,used+9,false);
			for(int i = r*3;i < r*3+3;i++)
				for(int j = c*3; j < c*3 + 3; j++)
					if(!check(sodu[i][j],used))
						return false;
		}
		
		return true;

	}
	bool check(char c, bool used[])
	{
		if(c == '.')
			return true;
		if(used[c-'1'])
			return false;
		return used[c-'1'] = true;
	}
};

int main(int argc,char  *argv[])
{
	vector<vector<char>> sodu = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}};

	Solution s;
	if(s.isValidSodu(sodu))
	{
		cout << "valid "<< endl;
	}
	else
		cout << "unvalid" << endl;

	return 0;
}
