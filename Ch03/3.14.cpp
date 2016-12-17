#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution{
public:
    string SimplifyPath(string str)
    {
        vector<string> dirs;       
        for(auto i = str.begin(); i != str.end();)
        {
            i++;
            auto j = find(i,str.end(),'/');
            string dir = string(i,j);
            if(!dir.empty() && dir !=".")
            {
                if(dir == "..")
                {
                    if(!dirs.empty())
                    {
                        dirs.pop_back();
                    }
                }
                else
                {
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        stringstream ss;
        if(dirs.empty())
        {
            ss << '/';
        }
        else
        {
            for(auto d:dirs)
            {
                ss << '/' << d;
            }
        }

        return ss.str();
    }
};

int main(int argc,char *argv[])
{
    Solution s;
    string tmp = s.SimplifyPath("/a/./b/../../c/");
    cout << tmp << endl;
    return 0;
}