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
	ListNode *PartitionList(ListNode *list,int value)
	{
		ListNode LessLink(-1);
		ListNode GreatLink(-1);
		ListNode *l = &LessLink;
		ListNode *g = &GreatLink;
		while(list)
		{
				ListNode *temp = list;
				list = list->next;
				temp->next = NULL;
				if(temp->value < value)
				{
					l->next = temp;
					l = l->next;
				}
				else
				{
					g->next = temp;
					g = g->next;
				}
			
		}
		l->next = GreatLink.next;
		return LessLink.next;

	}
};

int main(int argc,char *argv[])
{
	ListNode *l = new ListNode(5);
	Solution s;
	l = s.InsertNode(l,2);
	l = s.InsertNode(l,3);
	l = s.InsertNode(l,4);
	l = s.InsertNode(l,2);
	l = s.InsertNode(l,2);
	l = s.InsertNode(l,1);
	l = s.InsertNode(l,5);
	s.PrintList(l);
	l = s.PartitionList(l,3);
	s.PrintList(l);
	return 0;
}
