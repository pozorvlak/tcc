#include <stdio.h>
#include "lexer.h"
#include "parser.h"
#include "options.h"

int accept(FILE *stream, token tok)
{
	if (verbose) printf("Next token is %d\n", next_token);
	if (next_token == dummy) {
		/* First token has not yet been read - read it! */
		get_token(stream);
	}
	if (verbose) printf("Next token is %d\n", next_token);
	if (next_token == tok) {
		get_token(stream);
		return 1;
	}
	return 0;
}

int factor(FILE *stream)
{
	if (verbose) printf("factor\n");
	if (accept(stream, integer)) {
		if (verbose) printf("Saw literal %d\n", literal);
		return literal;
	}
	die("Syntax error: expected literal", 42);
}

int term(FILE *stream)
{
	if (verbose) printf("term\n");
	int left = factor(stream);
	if (accept(stream, times)) {
		if (verbose) printf("Saw *\n");
		int right = term(stream);
		return left * right;
	} else if (accept(stream, divide)) {
		if (verbose) printf("Saw /\n");
		int right = term(stream);
		return left / right;
	} else {
		return left;
	}
}

int expression(FILE *stream)
{
	if (verbose) printf("expression\n");
	int left = term(stream);
	if (accept(stream, plus)) {
		if (verbose) printf("Saw +\n");
		int right = expression(stream);
		return left + right;
	} else if (accept(stream, minus)) {
		if (verbose) printf("Saw -\n");
		int right = expression(stream);
		return left - right;
	} else {
		return left;
	}
}

