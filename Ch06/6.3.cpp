#include "6.h"

class Solution
{
public:
	Solution(){};
	~Solution(){};
	ListNode *MergeKList(std::vector<ListNode *> v)
	{
		ListNode *p = v[0];
		for(int i = 1; i < v.size(); i++)
		{
			p = MergeTwoList(p,v[i]);
		}
		return p;
	}
	ListNode *MergeTwoList(ListNode *l1,ListNode *l2)
	{
		ListNode head(-1);
		ListNode *p = &head;
		while(l1 != nullptr || l2 != nullptr)
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
	std::vector<ListNode *> v;
	ListNode *head = new ListNode(1);
	ListNode *p = head;
	for (int i = 1; i < 4; ++i)
	{
		p->next = new ListNode(2 * i + 1);
		p = p->next;
	}

	v.push_back(head);

	ListNode *head2 = new ListNode(2);
	ListNode *p2 = head2;
	for (int i = 2; i < 4; ++i)
	{
		p2->next = new ListNode(2 * i);
		p2 = p2->next;
	}
	v.push_back(head2);
	ListNode *head3 = new ListNode(8);
	ListNode *p3 = head3;
	for (int i = 9; i < 12; ++i)
	{
		p3->next = new ListNode(i);
		p3 = p3->next;
	}
	v.push_back(head3);

	Solution s;
	ListNode *tmp = s.MergeKList(v);
	while(tmp)
	{
		cout << tmp->value << " ";
		tmp = tmp->next;
	}
	cout << endl;
	return 0;
}