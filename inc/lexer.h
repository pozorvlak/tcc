#ifndef LEXER_H
#define LEXER_H

typedef enum { integer, plus, minus, times, divide, open_brace, close_brace,
	open_paren, close_paren } token;

extern token next_token;
extern int literal;

void get_token(FILE *cfile);

#endif /* LEXER_H */
