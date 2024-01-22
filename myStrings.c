#include "myStrings.h"

// Rewrite this so that only pointers are used, no array concepts.

/**
 * copy characters of src to dst (including '\0')
 * We assume tht the caller has sufficient space!
 */
void myStrCpy(char *dst, char *src){
	while(*src!='\0'){
		*dst=*src;
		src++;
		dst++;
	}
	*dst=*src;
}

/**
 * returns the length of string s
 * this is the number of non-null characters in s
 */
int myStrLen(char *s){
	int len=0;
	while(*s!='\0'){
		s++;
		len++;}
	return(len);
}

/**
 * returns whether s is the empty string
 */
int myisStrEmpty(char *s){
	return *s=='\0';
}

/**
 * returns whether s1 is equal to s2
 */
int myisStrEQ(char *s1, char *s2){
	while(*s1==*s2 && *s1!='\0' && *s2!='\0'){
		s1++;
		s2++;
	}
	if(*s1=='\0' && *s2=='\0')return 1;
	else return 0;
}

