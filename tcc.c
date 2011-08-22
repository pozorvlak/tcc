#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SFILE_NAME "ignore_me.s"
char *asm_boilerplate =
"	.file	\"zero.c\"\n"
"	.text\n"
".globl main\n"
"	.type	main, @function\n"
"main:\n"
"	pushl	\%ebp\n"
"	movl	\%esp, \%ebp\n"
"	movl	$0, \%eax\n"
"	popl	\%ebp\n"
"	ret\n"
"	.size	main, .-main\n"
"	.ident	\"TCC 0.0.1\"\n"
"	.section	.note.GNU-stack,\"\",@progbits\n"
;

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
	fprintf(sfile, "%s", asm_boilerplate);
	fcall(!fclose(sfile), "Couldn't close input file", 2);
	return 0;
}

