#ifndef IR_H
#define IR_H

typedef enum {
	op_mult, op_add, op_div, op_sub, op_ld, op_st
} e_op;

typedef struct {
	e_op op;
	int lhs;
	int rhs;
	int addr;
} quad;

quad *new_quad();

#endif /* IR_H */
