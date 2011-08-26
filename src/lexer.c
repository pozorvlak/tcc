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
	while ((c = fgetc(stream)) != EOF)  {
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
		printf("Found integer! %d\n", i);
		literal = i;
	}
	return found_integer;
}

void discard_line(FILE *stream)
{
	int c = 0;
	do {
		c = fgetc(stream);
	} while (c != EOF && c != '\n');
}

void read_whitespace(FILE *stream)
{
	int c;
	while ((c = fgetc(stream)) != EOF) {
		printf("Reading whitespace: saw char %lc\n", c);
		if (c == '/') {
			int c2 = fgetc(stream);
			if (c2 == '/') {
				discard_line(stream);
			} else if (c2 != EOF) {
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
	printf("get_token\n");
	read_whitespace(stream);
	if (read_integer(stream)) {
		printf("Successfully read an integer, namely %d\n", literal);
		next_token = integer;
	} else {
		int c;	
		c = fgetc(stream);
		printf("Saw character %c\n", c);
		switch (c) {
			case EOF: break;
			case '+' : next_token = plus; break;
			case '-' : next_token = minus; break;
			case '*' : next_token = times; break;
			case '/' : next_token = divide; break;
			case '{' : next_token = open_brace; break;
			case '}' : next_token = close_brace; break;
			case '(' : next_token = open_paren; break;
			case ')' : next_token = close_paren; break;
			default  : die("Saw unrecognized character", 37);
		}
	}
}


