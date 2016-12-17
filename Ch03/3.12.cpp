#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

class Solution
{
public:
    string CountAndSay(int n)
    {
        string s = "1";
        while(n--)
        {
            s = getNext(s);
        }
        return s;
    }
    string getNext(string s)
    {
        stringstream ss;
        for(auto i = s.begin(); i != s.end();)
        {
            auto j = find_if(i,s.end(),bind1st(not_equal_to<char>(),*i));
            ss << distance(i,j) << *i;
            i = j;
        }
        return ss.str();
    }
};
int main(int argc,char *argv[])
{
    Solution s;
    cout << s.CountAndSay(3); 
    return 0;
}