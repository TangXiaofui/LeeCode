#include <iostream>
using namespace std;
class Solution{
public:
	double findMediaSortArray(int a[],int m,int b[],int n)
	{
		int sum = m+n;
		if(sum & 0x1)
			return find_kth(a,m,b,n,sum/2+1);
		else
			return (find_kth(a,m,b,n,sum/2)+find_kth(a,m,b,n,sum/2+1))/2;
	}
	double find_kth(int a[],int m,int b[],int n,int k)
	{
		if(m>n)
			return find_kth(b,n,a,m,k);
		if(m == 0)
			return b[k - 1];
		if(k == 1)
			return a[0] > b[0] ? b[0] : a[0];

		int pa = m > k / 2 ? k / 2 : m;
		int pb = k - pa;
		if(a[pa - 1] > b[pb - 1])
			return find_kth(a,m,b+pb,n-pb,k-pb);
		else if(a[pa - 1] < b[pb - 1])
			return find_kth(a+pa,m-pa,b,n,k-pa);
		else 
			return a[pa-1];
	}
};


int main(int argc,char *argv[])
{
	int a[] = {1,3,5,7,9};
	int b[] = {0,2,4,6,8};
	int m = sizeof(a)/sizeof(a[0]);
	int n = sizeof(b)/sizeof(b[0]);

	Solution s;
	cout << s.findMediaSortArray(a,m,b,n)  << endl;
	for(int i = 1 ; i <= m+n ; i++)
		cout << s.find_kth(a,m,b,n,i) << endl;
	return 0;
}



