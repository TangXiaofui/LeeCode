#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	bool isExist(std::vector<std::vector<char>> board, string word)
	{
		int m = board.size();
		int n = board[0].size();
		std::vector<std::vector<bool>> visited(m,std::vector<bool>(n,false));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (dfs(board,i,j,0,word,visited))
				{
					return true;
				}
			}
		}
		return false;
	}
	bool dfs(std::vector<std::vector<char>> &board,int x,int y,int start,string &word,std::vector<std::vector<bool>> &visited)
	{
		if (start == (int)word.size())
		{
			return true;
		}

		if (x < 0 || x > (int)board.size() || y < 0 || y > (int)board[0].size())
		{
			return false;
		}
		if (word[start] != board[x][y])
		{
			return false;
		}

		if (visited[x][y] == true)
		{
			return false;
		}

		visited[x][y] = true;
		bool ret = dfs(board,x+1,y,start+1,word,visited) ||
					dfs(board,x-1,y,start+1,word,visited)||
					dfs(board,x,y+1,start+1,word,visited)||
					dfs(board,x,y-1,start+1,word,visited);
		visited[x][y] = false;
		return ret;

	}
	
};


int main(int argc, char const *argv[])
{
	std::vector<std::vector<char>> board = {
		{'A','B','C','E'},
		{'S','F','C','S'},
		{'A','D','E','E'}
	};
	Solution s;
	cout << s.isExist(board,"ABCCED") << endl;
	cout << s.isExist(board,"SEE") << endl;
	cout << s.isExist(board,"ABCB") << endl;

	return 0;
}