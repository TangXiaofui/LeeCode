#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
    vector<string> Anagrams(vector<string> &strs)
    {
        vector<string> result;
        unordered_map<string,vector<string>> umap;
        for(auto str:strs)
        {
            string tmp = str;
            sort(str.begin(),str.end());
            umap[str].push_back(tmp);
        }
        for(auto it = umap.begin();it != umap.end();it++)
        {
            if(it->second.size() > 1)
            {
                result.insert(result.end(),it->second.begin(),it->second.end());
            }
        }
        return result;
    }     
};

int main(int argc,char *argv[])
{
    vector<string> strs = {"dormitory","dirtyroom","tea","eat","aaa"};
    Solution s;
    for(auto ss : s.Anagrams(strs))
    {
        cout << ss << endl;
    }
}
