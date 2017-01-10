#include "12.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	int LargestArea(std::vector<int> heights)
	{
		int result = INT_MIN;
		int start = 0;
		int end = heights.size()-1;
		while(start < end)
		{
			int area = min(heights[start],heights[end]) * (end - start);
			result = max(result,area);
			if (heights[start] < heights[end])
			{
				start++;
			}
			else
			{
				end--;
			}
		}
		return result;
	}
	
};
class Solution2{
public:
int maxArea(vector<int> &height) {
int start = 0;
int end = height.size() - 1;
int result = INT_MIN;
while (start < end) {
int area = min(height[end], height[start]) * (end - start);
result = max(result, area);
if (height[start] <= height[end]) {
start++;
} else {
end--;
}
}
return result;
}
};

int main(int argc, char const *argv[])
{
	std::vector<int> v = {3,1,5,7,1,6};
	Solution s;
	cout << s.LargestArea(v) << endl;
	Solution2 s2;
	cout << s2.maxArea(v) << endl;
	return 0;
}