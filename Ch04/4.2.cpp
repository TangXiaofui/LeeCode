#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    int LongestValidParenthess(string &str)
    {
        int last = -1;
        int max_len = 0;
        stack<int> stk;
        for(int i = 0 ; i < str.size(); i++)
        {
            if(str[i] == '(')
            {
                stk.push(i);
            }
            else
            {
                if(stk.empty())
                {
                    last = i;
                }
                else
                {
                    stk.pop();
                    if(stk.empty())
                    {
                        max_len = max(max_len,i-last);
                    }
                    else
                    {
                        max_len = max(max_len,i-stk.top());
                    }
                }
            }
        }
        return max_len;
    }
};


int main(int argc,char *argv[])
{
    string str("()()(())");
    Solution s;
    cout << s.LongestValidParenthess(str) << endl;
}