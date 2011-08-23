#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "die.h"

void die(char *error_msg, int exit_code)
{
	fprintf(stderr, "ERROR: %s, code %i\n", error_msg, errno);
	exit(exit_code);
}

int or_die(int succeeded, char *error_msg, int exit_code)
{
	if (!succeeded) {
		die(error_msg, exit_code);
	}
	return succeeded;
}

