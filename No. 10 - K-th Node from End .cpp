#include <iostream>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


//assuming k <= len
ListNode* findKth(ListNode* head, int k)
{
	if(k <= 0 || head == NULL)
		return NULL;
	ListNode* prev = head;
	ListNode* current = head;
	while(k-- > 1)
		current = current->next;
	while(current->next != NULL)
	{
		prev = prev->next;
		current = current->next;
	}
	return prev;
}

//assuming k <= len
ListNode* findKth(ListNode* head, int k)
{
	if(k <= 0 || head == NULL)
		return NULL;
	int len = 0;
	ListNode* current = head;
	while(current != NULL)
	{
		current = current->next;
		len++;
	}
	int step = len - k;
	current = head;
	while(step-- > 0)
		current = current->next;
	return current;
}


//assuming k <= len and k > 0
int findKthRec(ListNode* current, ListNode*& ret, int k)
{
	if(current == NULL)
		return 0;
	int level = findKthRec(current->next,ret,k);
	level++;
	if(level == k)
		ret = current;
	return level;
}

