#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


class Solution{
public:
    int LengthOfLastWord(string str)
    {
        auto first = find_if(str.rbegin(),str.rend(),::isalpha);
        auto end = find_if_not(first,str.rend(),::isalpha);
        return distance(first,end);
    }
};

int main(int argc,char *argv[])
{
    Solution s;
    cout  << s.LengthOfLastWord("hello  wfo  ");

}
