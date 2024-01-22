#include<stdio.h>
#include"myStrings.h"


void checkmyisStrEmpty(char *s, int expected){
	char *mess="ERR";
	int retVal=myisStrEmpty(s);
	if(expected == retVal)mess="OK ";
	printf("%s (return) = (%d) EXPECTED (%d) myisStrEmpty(%s)\n",mess,retVal, expected, s);
}
void checkmyStrLen(char *s, int expected){
	char *mess="ERR";
	int retVal=myStrLen(s);
	if(expected == retVal)mess="OK ";
	printf("%s (return) = (%d) EXPECTED (%d) myStrLen(%s)\n",mess,retVal, expected, s);
}

void checkmyisStrEQ(char *s1, char *s2, int expected){
	char *mess="ERR";
	int retVal=myisStrEQ(s1,s2);
	if(expected == retVal)mess="OK ";
	printf("%s (return) = (%d) EXPECTED (%d) myisStrEQ(%s,%s)\n",mess,retVal, expected, s1,s2);
}

void checkmyStrCpy(char *src, int len){
	char *mess="ERR";
	char buff[len+1];
	myStrCpy(buff, src);
	if(myisStrEQ(buff, src))mess="OK ";
	printf("%s myStrCpy(buff, %s)\n",mess,src);
}

int main(int argc, char *argv[]){
	char *s0 = "";
	char *s1 = "a";
	char *s2 = "ab";
	char *s3 = "abc";

	checkmyisStrEQ(s0,s0,1);
	checkmyisStrEQ(s0,s1,0);
	checkmyisStrEQ(s1,s0,0);
	checkmyisStrEQ(s0,s3,0);
	checkmyisStrEQ(s3,s0,0);
	checkmyisStrEQ(s2,s3,0);
	checkmyisStrEQ(s3,s2,0);
	checkmyisStrEQ(s1,s1,1);
	checkmyisStrEQ(s2,s2,1);
	checkmyisStrEQ(s3,s3,1);

	checkmyisStrEmpty(s0,1);
	checkmyisStrEmpty(s1,0);
	checkmyisStrEmpty(s2,0);
	checkmyisStrEmpty(s3,0);

	checkmyStrLen(s0,0);
	checkmyStrLen(s1,1);
	checkmyStrLen(s2,2);
	checkmyStrLen(s3,3);
	
	checkmyStrCpy(s0,5);
	checkmyStrCpy(s1,5);
	checkmyStrCpy(s2,5);
	checkmyStrCpy(s3,5);
}
