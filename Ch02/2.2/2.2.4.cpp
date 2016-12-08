#include "List.h"
class Solution{
public:
	ListNode *RemoveRepElem(ListNode *l)
	{
		ListNode *prev = l;
		
		for(ListNode *Cur = prev->next;Cur;Cur = prev->next)
		{
			if(Cur->value == prev->value)
			{
				prev->next = Cur->next;
				delete Cur;
			}
			else
				prev = prev->next;
		}
		return l;
	}
	ListNode *RemoveRepElem2(ListNode *head)
	{
		ListNode dummy(head->value+1);
		dummy.next = head;
		RecurRemove(&dummy,head);
		return dummy.next;
	}
	void RecurRemove(ListNode *prev,ListNode *cur)
	{
		if(cur == NULL)
			return ;
		if(prev->value == cur->value)
		{
			prev->next = cur->next;
			delete cur;
			RecurRemove(prev,prev->next);
		}
		else
		{
			RecurRemove(prev->next,cur->next);
		}
	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	l = InsertNode(l,5);
	l = InsertNode(l,4);
	l = InsertNode(l,3);
	l = InsertNode(l,3);
	l = InsertNode(l,2);
	PrintList(l);
	Solution s;
	l = s.RemoveRepElem2(l);
	PrintList(l);
	return 0;
}
