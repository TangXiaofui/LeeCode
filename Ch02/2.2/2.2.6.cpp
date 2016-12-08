#include "List.h"


class Solution{
public:
	ListNode *RotateList(ListNode *head,int k)
	{
		int len = 1;
		ListNode *p = head;
		while(p->next)
		{
			len++;
			p = p->next;
		}
		
		len = len - k%len;
		
		p->next = head;
		int i = 0;
		while(i < len)
		{
			p = p->next;
			i++;
		}
		
		head = p->next;
		p->next = NULL;
		return head;
		
	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	l = InsertNode(l,4);
	l = InsertNode(l,3);
	l = InsertNode(l,2);
	l = InsertNode(l,1);
	Solution s;
	PrintList(l);
	l = s.RotateList(l,2);
	PrintList(l);
	return 0;
}
