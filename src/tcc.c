#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define SFILE_NAME "ignore_me.s"
char *asm_boilerplate_start =
"	.file	\"zero.c\"\n"
"	.text\n"
".globl main\n"
"	.type	main, @function\n"
"main:\n"
"	pushl	\%ebp\n"
"	movl	\%esp, \%ebp\n";

char *asm_boilerplate_end = 
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
	FILE *cfile, *sfile;
	
	fcall(argc == 2, "I can only handle one argument for now", 3);
	cfile = fopen(argv[1], "r");
	fcall((int) cfile, "Couldn't open input file", 4);
	fcall((int) (sfile = fopen(SFILE_NAME, "w")),
		"Couldn't open output file", 1);
	fprintf(sfile, "%s", asm_boilerplate_start);
	fprintf(sfile, "%s", "\tmovl\t$0,\t\%eax\n");
	fprintf(sfile, "%s", asm_boilerplate_end);
	fcall(!fclose(sfile), "Couldn't close output file", 2);
	return 0;
}

