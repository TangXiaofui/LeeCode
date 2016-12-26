#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

struct ListNode
{
	int value;
	ListNode *next;
	ListNode(int v):value(v),next(nullptr){};
};