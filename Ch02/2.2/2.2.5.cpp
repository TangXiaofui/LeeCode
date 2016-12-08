#include "List.h"
class Solution{
public:
	ListNode *RemoveAllDupElem(ListNode *head)
	{
		if(!head || !head->next )
			return head;
		ListNode *p = head->next;
		if(p->value == head->value)
		{
			while(p && head->value == p->value)
			{
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			
			delete head;
			return RemoveAllDupElem(p);
		}
		else
		{
			head->next = RemoveAllDupElem(p);
			return head;
		}
	}
	ListNode *RemoveAllDupElem2(ListNode *head)
	{
			ListNode dummy(head->value+1);
			dummy.next = head;
			ListNode *prev = &dummy;
			ListNode *cur = prev->next;
			while(cur)
			{
				bool hasDup = false;
				while(cur->next && cur->value == cur->next->value)
				{
					hasDup = true;
					ListNode *tmp = cur;
					cur = cur->next;
					delete tmp;
				}	
				
				if(hasDup)
				{
					ListNode *tmp = cur;
					cur = cur->next;
					delete tmp;
					continue;
				}

				prev->next = cur;
				prev = prev->next;
				cur = cur->next;
			}
			prev->next = cur;
			return dummy.next;
	}
};

class Solution2
{
public:
	ListNode *RemoveAllDupElem(ListNode *l)
	{
		if(!l || !l->next )
			return l;
		ListNode *p = l->next;
		if(l->value == p->value)
		{
			while(p && p->value == l->value)
			{
				ListNode *tmp = p;
				p = p->next;
				delete tmp;
			}
			delete l;
			return RemoveAllDupElem(p);
		}
		else
		{
			l->next = RemoveAllDupElem(p);
			return l;
		}
	}
	ListNode *RemoveAllDupElem2(ListNode *l)
	{
		ListNode dummy(l->value+1);
		dummy.next = l;
		ListNode *prev = &dummy;
		ListNode *cur = prev->next;
		while(cur)
		{
			bool hasDup = false;
			while(cur->next && cur->value == cur->next->value)
			{
				hasDup = true;
				ListNode *tmp = cur;
				cur = cur->next;
				delete tmp;
			}
			
			if(hasDup)
			{
				ListNode *tmp = cur;
				cur = cur->next;
				delete tmp;
				continue;
			}

			prev->next = cur;
			prev = prev->next;
			cur = prev->next;
		}
		prev->next = cur;
		return dummy.next;
	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	l = InsertNode(l,5);
	l = InsertNode(l,5);
	l = InsertNode(l,4);
	l = InsertNode(l,3);
	l = InsertNode(l,3);
	l = InsertNode(l,2);
	l = InsertNode(l,2);
	PrintList(l);
	Solution2 s;
	l = s.RemoveAllDupElem2(l);
	PrintList(l);

	return 0;
}
