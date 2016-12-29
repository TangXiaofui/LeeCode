#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <set>
using namespace std;

void PrintElem(std::vector<std::vector<int>> result)
{
	for(auto res : result)
	{
		for(auto e : res)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
