/**
* Write a program to remove all comments from a C program. Don't forget to
* handle quoted strings and character constants properly.
* C comments don't nest.
**/

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
	char c, p;
	int inline_state = OUT;
	int multiline_state = OUT;

	while ((c = getchar()) != EOF) {
		if (c == '/' && p == '/')
			inline_state = IN;
		else if (c == '*' && p == '/')
			multiline_state = IN;
		
		if (!(inline_state || multiline_state))
			putchar(c);
		
		if (c == '\n' && inline_state)
			inline_state = OUT;
		if (c == '/' && p == '*' && multiline_state)
			multiline_state = OUT;
		
		p = c;
	}
}
