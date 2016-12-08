#include "List.h"
class Solution{
public:
	ListNode *SwapNodeInPairs(ListNode *l)
	{
		ListNode dummy(-1);
		dummy.next = l;
		for(ListNode *prev = &dummy,*cur = prev->next,*next = cur->next;
			next;
			prev = cur,cur = prev->next,next = cur == NULL?NULL:cur->next)
		{
			cur->next = next->next;
			next->next = cur;
			prev->next = next;
		}
		return dummy.next;
	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	l = InsertNode(l,4);
	l = InsertNode(l,3);
	l = InsertNode(l,2);
	PrintList(l);
	Solution s;
	l = s.SwapNodeInPairs(l);
	PrintList(l);
	
	return 0;
}
