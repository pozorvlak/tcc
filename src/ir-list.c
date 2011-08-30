#include "ir-list.h"
#include <assert.h>
#include <stdlib.h>

ir_list *new_list()
{
	void *v = malloc(sizeof(ir_list));
	ir_list *l = (ir_list *) v;
	l->first = NULL;
	l->last = NULL;
}

void push(ir_list *l, quad *q)
{
	assert(l != NULL);
	assert(q != NULL);
	void *v = malloc(sizeof(ir_node));
	ir_node *n = (ir_node *) v;
	n->value = q;
	ir_node* prev = l->last;
	if (prev == NULL) {
		/* list is empty; add first element */
		l->first = n;
		n->previous = NULL;
	} else {
		prev->next = n;
		n->previous = prev;
	}
	l->last = n;
	n->next = NULL;
}

int length(ir_list *l)
{
	assert(l != NULL);
	int len = 0;
	ir_node *n = l->first;
	while (n != NULL) {
		len++;
		n = n->next;
	}
	return len;
}

void delete_node(ir_list *l, ir_node* n)
{
	assert(l != NULL);
	assert(n != NULL);
	ir_node *prev, *next;
	prev = n->previous;
	next = n->next;
	if (prev != NULL) {
		prev->next = next;
	} else {
		assert(l->first == n);
		l->first = next;
	}
	if (next != NULL) {
		next->previous = prev;
	} else {
		assert(l->last == n);
		l->last = prev;
	}
	free(n->value);
	free(n);
}

void delete_all(ir_list *l)
{
	assert(l != NULL);
	ir_node *n = l->first;
	while (n != NULL) {
		ir_node *next = n->next;
		free(n->value);
		free(n);
		n = next;
	}
	l->first = NULL;
	l->last = NULL;
}


