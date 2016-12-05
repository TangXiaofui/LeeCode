#include <iostream>
using namespace std;
struct ListNode{
	int value;
	ListNode *next;
	ListNode(int v):value(v),next(NULL)
	{}
};


class Solution{
public:
	ListNode *AddTwoNumber(ListNode *l1,ListNode *l2)
	{
		ListNode head(-1);
		int carry = 0;
		int value;
		ListNode *prev = &head;
		for(ListNode *a1 = l1,*a2 = l2;
		a1 != NULL || a2 != NULL;
		a1 == NULL ? NULL: a1 = a1->next,
		a2 == NULL ? NULL: a2 = a2->next)
		{
			int v1 = a1 != NULL? a1->value : 0;
			int v2 = a2 != NULL? a2->value : 0;
			value = (v1 + v2 + carry);
			carry = value / 10;
			value = value % 10;
			ListNode *tmp = new ListNode(value);
			prev->next = tmp;
			prev = tmp;			
		}

		if(carry > 0)
		{
			ListNode *tmp = new ListNode(value);
			prev->next = tmp;
		}
			return head.next;
			
	}
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
};

int main(int argc,char *argv[])
{
	ListNode *l1 = NULL;
	Solution s;
	l1 = s.InsertNode(l1,3);
	l1 = s.InsertNode(l1,4);
	l1 = s.InsertNode(l1,4);
	s.PrintList(l1);		
	
	ListNode *l2 = NULL;
	l2 = s.InsertNode(l2,4);
	l2 = s.InsertNode(l2,6);
	l2 = s.InsertNode(l2,5);
	s.PrintList(l2);	

	ListNode *tmp =	s.AddTwoNumber(l1,l2);
	s.PrintList(tmp);
	return 0;
}
