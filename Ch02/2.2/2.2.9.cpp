#include "List.h"
class Solution{
public:
	ListNode *RotateNodesInKGroup(ListNode *head,int k){
		if(head == NULL || head->next == NULL || k < 2)
		return head;
		int i = 0;
		ListNode *p_next = head;
		for(i = 0 ; i < k && p_next ;i++)
		{
			p_next = p_next->next;
		}
		if(i != k)
			return head;
		ListNode *new_next_group = RotateNodesInKGroup(p_next,k);
		i = 0;
		ListNode *cur,*next;
		for(cur = head,next = cur->next;;i++)
		{
			if(i >=k)
			break;
			cur->next = new_next_group;
			new_next_group = cur;
			cur = next;
			next = cur->next;
		}	
			
		return new_next_group;	
	}
	ListNode *RotateNodesInKGroup2(ListNode *head,int k){
		if(head == NULL || head->next == NULL || k < 2)
			return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode *end = head;
		int i ;
		for(ListNode *prev = &dummy;end;end = prev->next)
		{
			for(i = 1; i < k && end;i++)
				end = end->next;
			if(end == NULL)
				break;
			prev = reverse(prev,prev->next,end);		
		}
		return dummy.next;
	}
	ListNode *reverse(ListNode *prev,ListNode *begin,ListNode *end)
	{
		ListNode *cur,*next;
		for(cur = begin,next = cur->next;;)
		{
			cur->next = next->next;
			next->next = prev->next;
			prev->next = next;
			next = cur->next;
			if(prev->next == end)
				break;
		}	
		return cur;
	
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
	l = s.RotateNodesInKGroup2(l,2);
	PrintList(l);
	
	return 0;
}
