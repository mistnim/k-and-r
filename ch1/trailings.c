/* Exercise 1-18 Write a program to remove trailing blanks and tabs from each line of input,
 * and to delete entirely blank lines. */


#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    char line[MAXLINE];
    int len;
    while ((len = getline(line, MAXLINE)) > 0) {
        int i = len - 1;
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'))
            --i;
        if (i != -1) {
            line[i + 1] = '\0';
            printf("%s\n", line);
        }
    }
    return 0;
}

int getline(char s[], int lim) {
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    if (i == lim-1 && c != '\n') {
        while ((c=getchar())!=EOF && c!= '\n')
            ++i;
        if (c == '\n')
            ++i;
    }
    return i;
}

void copy(char to[], char from[]) {
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
