#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void printInt(int x) {
	printf("%d\n", x);
}

void printString(const char* s) {
	printf("%s\n",s);
}

void error() {
    printf("runtime error\n");
	exit(1);
}

int readInt() {
	int res;
    scanf("%d\n", &res);
	return res;
}

char* readString() {
	char* line = NULL;
    size_t siz = 0;
    getline(&line, &siz, stdin);

    int len = strlen(line);
	line[len - 1] = '\0';
	return line;
}

char* __concatStrings(const char* a, const char* b) {
	int len1 = strlen(a);
    int len2 = strlen(b);
    int newLen = len1 + len2 + 1;
    char* res = (char*) malloc(sizeof(char) * newLen);
    
    memcpy(res, a, len1);
    memcpy(res + len1, b, len2);

	return res;
}
