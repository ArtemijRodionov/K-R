/**
* Write a program detab that replaces tabs in the input with the
* proper number of blanks to space to the next tab stop. Assume a
* fixed set of tab stops, say every n columns.
**/

#include <stdio.h>

#define SPACES 4

int main() {
	int	i, c, cursor = 0, expansion = 0;

	while((c = getchar()) != EOF){
		switch (c) {
			case '\t':
				expansion = SPACES - (cursor % SPACES);
				for (i = 0; i < expansion; ++i) {
					putchar(' ');
				}
				break;
			case '\n':
				putchar(c);
				cursor = 0;
				break;
			default:
				putchar(c);
				++cursor;
				break;
		}
	}

	return 0;
}
