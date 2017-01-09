#include "10.h"
using namespace std;


class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool SodukuSolver(std::vector<std::vector<char>> &board)
	{
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					for (int k = 1; k <= 9; ++k)
					{
						board[i][j] = '0'+k;
						if (isValid(board,i,j) && SodukuSolver(board))
						{
							return true;
						}
						board[i][j] = '.';
					}
					return false;  //单个位置每个数字都遍历过，但都失败，所以返回错误
				}
			}
		}
		return true; //全部数字都填完
	}
	bool isValid(std::vector<std::vector<char>> &board,int x, int y)
	{
		for (int i = 0; i < 9; ++i)
		{
			if (i != x && board[i][y] == board[x][y])
			{
				return false;
			}
		}
		for (int i = 0; i < 9; ++i)
		{
			if (i != y && board[x][i] == board[x][y])
			{
				return false;
			}
		}

		for (int i = 3 * ( x / 3) ; i < (x/3 + 1) * 3; ++i)
		{
			for (int j = 3 * (y / 3); j < (y / 3 + 1) *3; ++j)
			{
				if ( i != x && j != y && board[x][y] == board[i][j])
				{
					return false;
				}
			}
		}
		return true;
	}
	
};

int main(int argc, char const *argv[])
{
	std::vector<std::vector<char>> board = {
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'}
	};
	Solution s;
	s.SodukuSolver(board);
	for(auto row : board)
	{
		for(auto elem : row)
		{
			cout << elem << " ";
		}
		cout << endl;
	}
	return 0;
}