/* Exercise 1-20. Write a program detab that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a fixed set of
 * tab stops, say every n columns. Should n be a variable or a symbolic
 * parameter? */

#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 8

int getline(char line[], int maxline);
void copy(char to[], char from[]);

void print_detab(char s[]) {
    int i, mi;
    i = mi = 0;
    while (i < MAXLINE && s[i] != '\0') {
        if (s[i] != '\t')
            putchar(s[i]);
        else {
            putchar(' ');
            while (mi < TAB_SIZE - 1) {
                putchar(' ');
                ++mi;
            }
        }
        ++i;
        mi = (mi + 1) % TAB_SIZE;
    }
}

int main() {
    char line[MAXLINE];
    int len;
    while ((len = getline(line, MAXLINE)) > 0) {
        print_detab(line);
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
