#include "6.h"

class Solution
{
public:
	Solution(){};
	~Solution(){};
	ListNode* MergeTwoList(ListNode *l1,ListNode *l2)
	{
		ListNode head(-1);
		for(ListNode *p = &head ; l1 != nullptr || l2 != nullptr ;)
		{
			int v1 = l1 == nullptr ? INT_MAX : l1->value;
			int v2 = l2 == nullptr ? INT_MAX : l2->value;
			if (v1 > v2)
			{
				p->next = l2;
				l2 = l2->next;
			}
			else
			{
				p->next = l1;
				l1 = l1->next;
			}
			p = p->next;
		}
		return head.next;
	}
	
};


int main(int argc, char const *argv[])
{
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 1; i < 4; ++i)
	{
		p->next = new ListNode(2 * i + 1);
		p = p->next;
	}

	ListNode *head2 = new ListNode(2);
	ListNode *p2 = head2;
	for (int i = 2; i < 4; ++i)
	{
		p2->next = new ListNode(2 * i);
		p2 = p2->next;
	}

	Solution s;
	ListNode *l = s.MergeTwoList(head,head2);

	ListNode *tmp = l;
	while(l)
	{
		cout << l->value << " ";
		l = l-> next;
	}
	cout << endl;

	return 0;
}