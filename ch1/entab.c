/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab . When either a tab or a single blank would suffice to reach a tab stop, which should be given preference? */

#include <assert.h>
#include <stdio.h>
#define MAXLINE 1000
#define TAB_SIZE 4

int mygetline(char line[], int maxline);
void copy(char to[], char from[]);

void print_escaped(char s[]) {
    int i = 0;
    char c;
    while ((c = s[i++]) != '\0') {
        if (c == '\t')
            printf("\\t");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
    }
}

void entab(char s[]) {
    int ir = 0;
    int iw = 0;
    while (1) {
        int tblanks = 0;
        for (int i = 0; i < TAB_SIZE; ++i) {
            s[iw+i] = s[ir+i];
            if (s[ir+i] == ' ')
                tblanks++;
            else if (s[ir+i] == '\0')
                goto stop;
            else
                tblanks = 0;
        }
        /* if only one trailing space keep it */
        if (tblanks == 1)
            tblanks = 0;
        iw = iw + TAB_SIZE - tblanks;
        ir += TAB_SIZE;
        if (tblanks > 0)
            s[iw++] = '\t';
    }
 stop: return;
}

int main() {
    char line[MAXLINE];
    int len;
    while ((len = mygetline(line, MAXLINE)) > 0) {
        entab(line);
        print_escaped(line);
    }
    return 0;
}

int mygetline(char s[], int lim) {
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
