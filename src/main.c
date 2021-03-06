#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "die.h"
#include "options.h"
#include "boilerplate.h"

int verbose = 0;

/**
 * Given the name of a source file, return the name of the corresponding
 * assembly (.s) file.
 */
char *get_sfile_name(const char *cfile_name)
{
	int length = strlen(cfile_name);
	char *sfile_name = calloc(length + 3, sizeof(char));
	or_die(sfile_name != NULL, "Out of memory", 3);
	if ((cfile_name[length-1] == 'c') && (cfile_name[length-2] == '.')) {
		length -= 2;
	}
	strncpy(sfile_name, cfile_name, length * sizeof(char));
	strncpy(sfile_name + length, ".s", 2 * sizeof(char));
	return sfile_name;
}

/**
 * Compile the code in cfile, placing the assembly-language output in sfile.
 */
void compile(FILE *cfile, FILE *sfile, char* cfile_name)
{
	fprintf(sfile, ASM_BOILERPLATE_START, cfile_name);
	int retval = expression(cfile);
	fprintf(sfile, ASM_RETURN_LINE, retval);
	fprintf(sfile, ASM_BOILERPLATE_END);
}

int main(char argc, char** argv)
{
	FILE *cfile, *sfile;
	int i;
	
	for (i = 1; i < argc; i++) {
		char *cfile_name = argv[i];
		cfile = fopen(cfile_name, "r");
		or_die(cfile != NULL, "Couldn't open input file", 4);
		char *sfile_name = get_sfile_name(cfile_name);
		sfile = fopen(sfile_name, "w");
		or_die(sfile != NULL, "Couldn't open output file", 1);
		free(sfile_name);
		compile(cfile, sfile, cfile_name);
		or_die(fclose(sfile) == 0, "Couldn't close output file", 2);
	}
	return 0;
}

