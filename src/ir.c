#include "ir.h"
#include "die.h"
#include <stdlib.h>

quad *new_quad()
{
	void *v = malloc(sizeof(quad));
	quad *q = (quad *) v;
	q->op = op_mult;
	q->lhs = 0;
	q->rhs = 0;
	q->addr = 0;
	return q;
}

