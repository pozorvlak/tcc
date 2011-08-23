#ifndef PARSER_H
#define PARSER_H

int factor(FILE *stream);
int term(FILE *stream);
int expression(FILE *stream);

#endif /* PARSER_H */
