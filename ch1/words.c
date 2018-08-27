// Exercise 1.12

#include <stdio.h>
#define IN 1
#define OUT 0
#define true 1
#define false 0
void main()
{
    int c, nl, nw, nc, state;
    int start = true;
    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            if (start == false) {
                putchar('\n');
            }
            putchar(c);
        } else {
            putchar(c);
        }
        start = false;
    }
    printf("\n");
}
