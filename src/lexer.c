#include <stdio.h>

int read_integer(FILE *stream)
{
	int i = 0;
	int c;
	while (c = fgetc(stream)) {
		if (isdigit(c)) {
			i *= 10;
			i += (c - '0');
		} else {
			ungetc(c, stream);
			break;
		}
	}
	return i;
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


