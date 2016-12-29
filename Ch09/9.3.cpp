#include "9.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};

	void SurroundRegions(std::vector<std::vector<char>> &board)
	{
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i < m; ++i)
		{
			bfs(board,i,0);
			bfs(board,i,n-1);
		}
		for (int i = 0; i < n; ++i)
		{
			bfs(board,0,i);
			bfs(board,m-1,i);
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == '+')
				{
					board[i][j] = 'O';
				}
				if (board[i][j] == 'O')
				{
					board[i][j] = 'X';
				}
			}
		}

	}
	void bfs(std::vector<std::vector<char>> &board,int row,int col)
	{
		queue<int> q;
		visit(board,row,col,q);
		while(!q.empty())
		{
			int pos = q.front();
			q.pop();
			int x = pos/board[0].size();
			int y = pos%board[0].size();
			visit(board,x-1,y,q);
			visit(board,x+1,y,q);
			visit(board,x,y-1,q);
			visit(board,x,y+1,q);
		}
	}
};


int main(int argc, char const *argv[])
{
	std::vector<std::vector<char>> board = {
		{'X','X','X','X'},
		{'X','O','O','X'},
		{'X','X','O','X'},
		{'X','O','X','X'}
	};
	Solution s;
	s.SurroundRegions(board);
	for(auto row : board)
	{
		for(auto col : row)
		{
			cout << col << " ";
		}
		cout << endl;
	}
	return 0;
}