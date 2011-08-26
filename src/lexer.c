#include <stdio.h>
#include "lexer.h"
#include "die.h"

token next_token = dummy;
int literal;

int read_integer(FILE *stream)
{
	int i = 0;
	int c;
	int found_integer = 0;
	while (c = fgetc(stream)) {
		if (isdigit(c)) {
			found_integer = 1;
			i *= 10;
			i += (c - '0');
		} else {
			ungetc(c, stream);
			break;
		}
	}
	if (found_integer) {
		literal = i;
	}
	return found_integer;
}

void discard_line(FILE *stream)
{
	int c = 0;
	do {
		c = fgetc(stream);
	} while (c != '\n');
}

void read_whitespace(FILE *stream)
{
	int c;
	while (c = fgetc(stream)) {
		if (c == '/') {
			int c2 = fgetc(stream);
			if (c2 == '/') {
				discard_line(stream);
			} else {
				ungetc(c2, stream);
				ungetc(c, stream);
			}
		} else if (!isspace(c)) {
			ungetc(c, stream);
			break;
		}
	}
}

/* Read the next token from stream. Puts the next token in next_token. */
void get_token(FILE *stream)
{
	read_whitespace(stream);
	if (read_integer(stream)) {
		next_token = integer;
	} else {
		int c;	
		c = fgetc(stream);
		switch (c) {
			case '+' : next_token = plus; break;
			case '-' : next_token = minus; break;
			case '*' : next_token = times; break;
			case '/' : next_token = divide; break;
			case '{' : next_token = open_brace; break;
			case '}' : next_token = close_brace; break;
			case '(' : next_token = open_paren; break;
			case ')' : next_token = close_paren; break;
		}
	}
}


