#include "10.h"
using namespace std;

class Solution
{
public:
	Solution(){};
	~Solution(){};
	std::vector<string> RestoreIPAddress(string IP)
	{
		std::vector<string> result;
		string path;
		dfs(IP,0,0,path,result);
		return result;
	}
	void dfs(string &IP,int start,int step, string s,std::vector<string> &result)
	{

		if (step == 4 && start == IP.size())		//双重判断
		{
			result.push_back(s);
			return ;
		}

		if (IP.size() - start > (4-step)*3)       //-start
		{
			return ;
		}

		if (IP.size() - start < (4-step))		//-start
		{
			return ;
		}
		int num = 0;
		for (int i = start; i < start+3; ++i)
		{
			num = num * 10 + IP[i] - '0';

			if (num <= 255)						//!!!!!!!!!!!!!!!
			{
				s+=IP[i];						//!!!!!!!!!!!!!!!
				dfs(IP,i+1,step+1,s+'.',result);
			}
			
			if (num == 0)
			{
				break;
			}
		}

	}
};


class Solution2
{
public:
	Solution2(){};
	~Solution2(){};
	std::vector<string> RestoreIPAddress(string ip)
	{
		std::vector<string> result;
		string path;
		dfs(ip,0,0,path,result);
		return result;
	}
	void dfs(string ip,int start,int step,string path,std::vector<string> &result)
	{
		if (start == ip.size() && step == 4)
		{
			result.push_back(path);
			return ;
		}

		if (ip.size() - start > (4-step) * 3)
		{
			return;
		}
		
		if (ip.size() - start < (4-step))
		{	
			return ;
		}
		int num = 0;
		for (int i = start; i < 3+start; ++i)
		{
			num = num*10 + ip[i] - '0';
			if (num <= 255)
			{
				path += ip[i];
				dfs(ip,i+1,step+1,path+'.',result);
			}
			if (num == 0)
			{
				break;
			}
		}
	}
	
};


int main(int argc, char const *argv[])
{
	Solution2 s;
	auto result = s.RestoreIPAddress("25525511135");
	for(auto r : result)
	{
		cout << r << endl;
	}
	return 0;
}