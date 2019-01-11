// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

typedef struct _iobuf {
    char* _ptr;
    int _cnt;
    char* _base;
    int _flag;
    int _file;
    int _charbuf;
    int _bufsiz;
    char* _tmpfname;
} FILE;
extern FILE* stdin;

extern int printf(const char* fmt, ...);
extern int scanf(const char* fmt, ...);
extern void exit(int code);
extern int getline(char** lineptr, unsigned int* n, FILE* stream);
extern unsigned int strlen(const char* str);
void* malloc(unsigned int size);
void* memcpy(void* destination, const void* source, unsigned int num);
#define NULL ((void*)0)

void printInt(int x) {
    printf("%d\n", x);
}

void printString(const char* s) {
    printf("%s\n", s);
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
    unsigned int siz = 0;
    getline(&line, &siz, stdin);

    int len = strlen(line);
    line[len - 1] = '\0';
    return line;
}

char* __concatStrings(const char* a, const char* b) {
    int len1 = strlen(a);
    int len2 = strlen(b);
    int newLen = len1 + len2 + 1;
    char* res = (char*)malloc(sizeof(char) * newLen);

    memcpy(res, a, len1);
    memcpy(res + len1, b, len2);

    return res;
}
