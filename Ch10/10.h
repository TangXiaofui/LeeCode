#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

using namespace std;
template <typename Target>
void PrintElem(Target result)
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
