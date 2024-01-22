#include <stdio.h>
#include "myStrings.h"
#include "parseArgs.h"

int iWord=-1, iFileName=-1;

/**
 * print the usage message
 */
void usage(){
	printf("This is the usage message for the hasWord program (accessed by typing './hasWord --help').\n"
		   "1st argument: the pattern you wish to find.\n"
		   "2nd argument: the file you wish to find the pattern in, or leave it blank to read from stdin.\n"
		   "If you require the help page, write '--help' as your argument in any position you wish. However if '--help' is found, pattern will not be checked.\n");
}
/**
 * print error message to stderr
 */
void optionsError(char mesg[]){
	fprintf(stderr, "hasWord: %s\nTry 'hasWord --help' for more information.\n", mesg);
}
/**
 * parse and understand the args. 
 * returns 1 for success, 0 for error, 2 for --help printed
 * On success, iWord, iFileName are all properly initialized
 * iFileName == -1 indicates read from stdin
 */
int parseArgs(int argc, char *argv[]){
	// check if --help is any of the arguments by looping over them
	char help[] = "--help";
	char *pH = &help[0];
	for (int arg = 1; arg < argc; arg++) {
			char *arg_init = argv[arg];
			if (myisStrEQ(pH, arg_init) == 1){
				usage();
				return 2;
			} 
	}
	/** case is when user runs: 
	$ hasWord 
	or 
	$ hasWord arg1 arg2 arg3 .....
	*/
	if (argc <= 1 || argc > 3) {
        iWord = -1;
		iFileName = -1;
		optionsError("incorrect number of arguments");
        return 0;}
	// case is when user runs: $ hasWord word 
	if (argc == 2) {
		iWord = 1;
		iFileName = -1;
		return 1;}
	// case is when user runs: $ hasWord word fileName
	if (argc == 3) {
        iWord = 1;
		iFileName = 2;
		return 1;}
	return 0;
}
