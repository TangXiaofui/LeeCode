#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
public:
	void RotateImage(vector<vector<int>> &img)
	{
		int row = img.size();
		int col = img[0].size();
		for(int i = 0 ; i < row ;i++)
			for(int j = 0 ; j < col-i - 1 ; j++)
				swap(img[i][j],img[col-j-1][row-i-1]);
	
		for(int i = 0 ; i < row/2 ;i++)
			for(int j = 0; j < col ; j++)
			 	swap(img[i][j],img[row-i-1][j]);
	}

		
	void printVector(const vector<vector<int>> & img)
	{
		for(auto row:img)
		{	
			for(auto i : row)
				cout << i << " ";
			cout << endl;
		}
	}
};
int main(int argc,char *argv[])
{
	vector<vector<int>> img = {
				{1,2,3,4},
				{5,6,7,8},
				{9,10,11,12},
				{13,14,15,16}};
	Solution s;
	s.printVector(img);
	s.RotateImage(img);
	s.printVector(img);
	return 0;
}
