/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};
void swap(struct node *p1, struct node*p2);
struct node * sortLinkedList(struct node *head) {
	if (head == NULL)
		return NULL;
	if (head->next == NULL)
		return head;
	struct node* first = head;
	struct node* second;
	struct node* min;

	while (first->next)
	{
		min = first;
		second = first->next;
        while (second)
		{
			if (min->num > second->num)
				min = second;
			second = second->next;
		}
		swap(first, min);
		first = first->next;
	}
	return head;
}
void swap(struct node *p1, struct node*p2)
{
	int temp;
	temp = p1->num;
	p1->num = p2->num;
	p2->num = temp;
}
