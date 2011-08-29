#ifndef IR_LIST_H
#define IR_LIST_H

#include "ir.h"

typedef struct ir_list_node {
	struct ir_list_node *previous;
	struct ir_list_node *next;
	quad *value;
} ir_node;

typedef struct {
	ir_node* first;
	ir_node* last;
} ir_list;


ir_list *new_list();
void push(ir_list *l, quad *q);
int length(ir_list *l);
void delete_node(ir_node* n);
void delete_all(ir_list *l);

#endif /* IR_LIST_H */
