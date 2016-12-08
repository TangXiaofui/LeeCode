#include "List.h"

class Solution{
public:
	void RemoveNthNodeFromEndOfList(ListNode *l,int n)
	{
		ListNode *p = l;
		ListNode *q = l;
		for(int i = 0; i < n;i++)
		{
			p = p->next;
		}
		while(p->next)
		{
			p = p->next;
			q = q->next;
		}
		
		ListNode *tmp = q->next;
		q->next = q->next->next;
		delete tmp;
	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	l = InsertNode(l,4);
	l = InsertNode(l,3);
	l = InsertNode(l,2);
	l = InsertNode(l,1);
	PrintList(l);
	Solution s;
	s.RemoveNthNodeFromEndOfList(l,2);
	PrintList(l);
	
	return 0;
}
