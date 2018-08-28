// Exercise 1.12

#include <stdio.h>
#define IN 1
#define OUT 0
#define MAX_LENGTH 15
void main()
{
    int hist[MAX_LENGTH];
    for (int i = 0; i < MAX_LENGTH; ++i)
        hist[i] = 0;
    int wl = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (wl > 0) {
                if (wl > MAX_LENGTH)
                    wl = MAX_LENGTH - 1;
                hist[wl]++;
                wl = 0;
            }
        } else {
            wl ++;
        }
    }
    if (wl > 0) {
        if (wl > MAX_LENGTH)
            wl = MAX_LENGTH - 1;
        hist[wl]++;
    }
    for (int i = 0; i < MAX_LENGTH; ++i) {
        printf("%2d ", i);
        for (int j = 0; j < hist[i]; ++j) {
            putchar('*');
        }
        putchar('\n');
    }
}
