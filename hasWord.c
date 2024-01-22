#include <stdio.h>
#include <stdlib.h>
#include "myStrings.h"
#include "parseArgs.h"

/**
 * return whether word appears in open fpin
 */
int isWordInFile(char word[], int wordLen, FILE *fpin){
	int index = 0;
    // populates wordarray with first wordlen characters of the file
	char wordarray[wordLen]; 
    while (index < wordLen){
        int c = fgetc(fpin);
        if (c == '\n' || c == EOF){
            return 1;
        }
        wordarray[index] = c;
        index++;
    }
    wordarray[wordLen] = '\0';
    int c = fgetc(fpin);
    while ((fpin == stdin && c != '\n') || fpin != stdin && c != EOF) {
        if(myisStrEQ(word, wordarray) == 1){
            return 0;
        }
        else{
            for(int i = 0; i < wordLen-1 ; i++){
                wordarray[i] = wordarray[i + 1];
            }
            wordarray[wordLen-1] = c;
            if(myisStrEQ(word, wordarray) == 1){
                return 0;
            }
            c = fgetc(fpin);
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
	FILE *fpin; 
	int retVal=parseArgs(argc, argv);
	// if help was called
	if (retVal == 2){
		exit(0);
	}
	// if incorrect arguments were called
	if (retVal == 0){
		exit(127);
	}
	// when user passes a word (ifile=-1), or a word and a file (ifile=2)
	if (retVal == 1){
		char curr[myStrLen(argv[1]) + 1];
		myStrCpy(curr, argv[1]);
		if (iFileName == -1){ // 
			fpin = stdin;
			int result = isWordInFile(curr, myStrLen(argv[1]), fpin);
			if (result == 1){
				printf("The word %s is not in stdin.\n", argv[1]);
				exit(1);
			}
			printf("The word %s is in stdin. Congrats!\n", argv[1]);
			exit(0);
		}
		else {
			if (fpin == NULL){ // if file doesnt exist
				perror("Error: file does not exist.\n");
				exit(127);
			}
			fpin = fopen(argv[2], "r");
			int result = isWordInFile(curr, myStrLen(argv[1]), fpin);
			if (result == 1){
				printf("The word %s is not in this file.\n", argv[1]);
				exit(1);
			}
			printf("The word %s is in this file. Congrats!\n", argv[1]);
			exit(0);
		}
	}
}
