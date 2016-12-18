#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

class Solution{
public:
    bool isValid(const string &s)
    {
        string left = "({[";
        string right = ")}]";
        stack<char> ss;
        for(auto i:s)
        {
            if(left.find(i) != string::npos)
            {
                ss.push(i);
            }
            else 
            {
                if(ss.empty() || ss.top() != left[right.find(i)] )
                    return false;
                else
                    ss.pop();
            }
        }
        return ss.empty();
    }    
};

int main(int argc,char *argv[])
{
    Solution s;
    cout << s.isValid("{()}");
    return 0;
}
