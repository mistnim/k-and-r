// Exercise 1.9

#include <stdio.h>

void main() {
    int c;
    int pc = 'a';
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if (pc != ' ')
                putchar(' ');
        } else {
            putchar(c);
        }
        pc = c;
    }
}
