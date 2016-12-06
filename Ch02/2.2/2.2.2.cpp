#include <iostream>
using namespace std;

struct ListNode{
	int value;
	ListNode *next;
	ListNode(int v):value(v),next(NULL){}
};


class Solution{
public:
	ListNode *InsertNode(ListNode *l,int value)
	{
		ListNode *tmp = new ListNode(value);
		tmp->next = l;
		return tmp;
	}
	void PrintList(ListNode *l)
	{
		while(l)
		{
			cout << l->value << " ";
			l = l->next;
		}
		cout << endl;
	}
	
	ListNode *ReverseLinkII(ListNode *l,int m,int n)
	{
		ListNode tmp(-1);
		tmp.next = l;
		ListNode *prev_m = NULL;
		ListNode *prev = &tmp;
		for(int i = 0 ; i <= n; i++)
		{
			if( i == m )
				prev_m = prev;
			
			if(i > m && i <= n)
			{
				prev->next = l->next;
				l->next = prev_m->next;
				prev_m->next = l;
				l = prev;
			}
	
			prev = l;
			l = l->next;
		}
		return tmp.next;
	}
};


int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(6);
	Solution s;
	l = s.InsertNode(l,5);
	l = s.InsertNode(l,4);
	l = s.InsertNode(l,3);
	l = s.InsertNode(l,2);
	l = s.InsertNode(l,1);

	s.PrintList(l);

	l=s.ReverseLinkII(l,1,4);
	s.PrintList(l);
	return 0;
}
