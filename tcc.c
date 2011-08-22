#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SFILE_NAME "ignore_me.s"

int fcall(int succeeded, char *error_msg, int exit_code)
{
	if (!succeeded) {
		fprintf(stderr, "ERROR: %s, code %i\n", error_msg, errno);
		exit(exit_code);
	}
	return succeeded;
}

int main(char argc, char** argv)
{
	FILE *sfile;
	
	fcall((int) (sfile = fopen(SFILE_NAME, "w")),
		"Couldn't open input file", 1);
	fprintf(sfile, "Hello, world!\n");
	fcall(!fclose(sfile), "Couldn't close input file", 2);
	return 0;
}

