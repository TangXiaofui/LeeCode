#include <iostream>
using namespace std;
struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
public:
	RandomListNode* CopyRandomList(RandomListNode *head)
	{
		RandomListNode *tmp = head;
		while(tmp)
		{
			RandomListNode *t = new RandomListNode(tmp->label);
			t->next = tmp->next;
			tmp->next = t;
			tmp = t->next;
		}

		tmp = head;
		while(tmp)
		{
			if(tmp->random) //!!!!!!!!!!!!
				tmp->next->random = tmp->random->next;
			tmp = tmp->next->next;
		}
		tmp = head;
		RandomListNode dummy(-1);
		RandomListNode *new_head;
		new_head = &dummy;
		while(tmp)
		{
			new_head->next = tmp->next;
			new_head = new_head->next;
			tmp->next = tmp->next->next; //!!!!!
			tmp = tmp->next;
		}
		return dummy.next;
	}
};

RandomListNode *InsertRandomList(RandomListNode *l,int value)
{
	RandomListNode *tmp = new RandomListNode(value);
	tmp->next = l;
	return tmp;
}

void PrintRandomList(RandomListNode *l)
{
	while(l)
	{
		cout << l->label << (l->next != NULL ? "->" : " ");
		l = l->next;
	}
	cout << endl;
}

int main(int argc,char *argv[])
{
	RandomListNode *tmp = new RandomListNode(5);
    tmp = InsertRandomList(tmp,4);
    tmp = InsertRandomList(tmp,3);
    tmp = InsertRandomList(tmp,2);
    tmp = InsertRandomList(tmp,1);
	PrintRandomList(tmp);
	Solution s;
	RandomListNode *t = s.CopyRandomList(tmp);
	
	PrintRandomList(t);
	return 0;
}

