#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct ListNode{
	int value;
	ListNode *next;
	ListNode(int v):value(v),next(NULL){}
};

ListNode *InsertNode(ListNode *l,int value)
{
	ListNode *temp = new ListNode(value);
	temp->next = l;
	return temp;
}

void PrintList(ListNode *l)
{
	while(l)
	{
		cout << l->value << (l->next == NULL ?" " :"->");
		l = l->next;
	}
	cout << endl;
}

#endif
