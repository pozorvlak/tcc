#include "tap.h"
#include "ir-list.h"
#include "ir.h"
#include <stdlib.h>

int main()
{
	plan_tests(22);
	quad *q = new_quad();
	ir_list *l = new_list();
	ok(length(l) == 0, "Empty list has length 0");
	push(l, q);
	ok(length(l) == 1, "List with one item has length 1");
	ok(l->first->value == q, "First item is the one we put in");
	ok(l->last->value == q, "Last item is also the one we put in");
	quad *q2 = new_quad();
	quad *q3 = new_quad();
	push(l, q2);
	push(l, q3);
	ok(length(l) == 3, "Now three items in list");
	ir_node *n = l->first;
	ok(n->value == q, "First item is still the one we put in");
	n = n->next;
	ok(n->value == q2, "Second item is the second one we put in");
	ir_node *n2 = n->next;
	ok(n2->value == q3, "Third item is the third one we put in");
	ok(n2->next == NULL, "Nothing after item 3");
	ok(n2->previous == n, "Predecessor of third item is second item");
	delete_node(l, n);
	ok(length(l) == 2, "Deleted a node; length now 2");
	n = l->first;
	ok(n->next == n2, "chain now goes 1st -> 3rd");
	ok(n2->previous == n, "chain now goes 1st -> 3rd");
	delete_node(l, n);
	ok(length(l) == 1, "Deleted first node; length now 1");
	ok(l->first == n2, "Last node now first");
	delete_node(l, n2);
	ok(length(l) == 0, "List is empty after deleting only node");
	ok(l->first == NULL, "First node is NULL");
	ok(l->last == NULL, "Last node is NULL");
	q = new_quad();
	q2 = new_quad();
	q3 = new_quad();
	push(l, q);
	push(l, q2);
	push(l, q3);
	ok(length(l) == 3, "Added three nodes back");
	delete_node(l, l->last);
	ok(length(l) == 2, "Deleted last node from 3-elt list");
	ok(l->last->value == q2, "Second-last element is now last");
	delete_all(l);
	ok(length(l) == 0, "List is empty after deleting everything");
	free(l);
	return 0;
}
