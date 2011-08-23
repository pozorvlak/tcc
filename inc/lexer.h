#ifndef LEXER_H
#define LEXER_H

int read_integer(FILE *stream);
void discard_line(FILE *stream);
void read_whitespace(FILE *cfile);

#endif /* LEXER_H */
