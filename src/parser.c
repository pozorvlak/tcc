#include <stdio.h>
#include "lexer.h"
#include "parser.h"

int accept(FILE *stream, token tok)
{
	if (next_token == tok) {
		get_token(stream);
		return 1;
	}
	return 0;
}

int factor(FILE *stream)
{
	if (accept(stream, integer)) {
		return literal;
	}
	die("Syntax error: expected literal", 42);
}

int term(FILE *stream)
{
	int left = factor(stream);
	if (accept(stream, times)) {
		int right = term(stream);
		return left * right;
	} else if (accept(stream, divide)) {
		int right = term(stream);
		return left / right;
	} else {
		return left;
	}
}

int expression(FILE *stream)
{
	int left = term(stream);
	if (accept(stream, plus)) {
		int right = expression(stream);
		return left + right;
	} else if (accept(stream, minus)) {
		int right = expression(stream);
		return left - right;
	} else {
		return left;
	}
}

