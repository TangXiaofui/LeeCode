#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution{
public:
    int LargestArea(vector<int> &height)
    {
        int max_area = 0;
        stack<int> stk;
        int i = 0;
        int len = height.size();
        while(i < len)
        {
            if(stk.empty() || height[i] > height[stk.top()])
            {
                stk.push(i++);
            }
            else
            {
                int tp = stk.top();
                stk.pop();
                int area = height[tp] * (stk.empty() ? i : i - stk.top() -1 );
                max_area = max(max_area,area);
            }
        }
        while(!stk.empty())
        {
            int tp = stk.top();
            stk.pop();
            int area = height[tp] * (stk.empty() ? i : i - stk.top() -1 );
            max_area = max(max_area,area);
        }
        return max_area;
    }
};


int main(int argc,char *argv[])
{
    vector<int> height = {2,1,5,6,2,3};
    Solution s;
    cout << s.LargestArea(height) ;
    return 0;
}