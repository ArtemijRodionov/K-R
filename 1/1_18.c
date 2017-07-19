#include <stdio.h>

#define MAXLINE 1000

/**
* Exercise 1-18. Write a program to remove trailing blanks and tabs
* from each line of input, and to delete entirely blank lines.
**/

void format(char line[], int maxline);

int main(int argc, char const *argv[])
{
	char formatted[MAXLINE];

	format(formatted, MAXLINE);
	for(int i = 0; formatted[i] != '\0'; ++i)
		putchar(formatted[i]);

	return 0;
}

void format(char s[], int lim)
{
	int c, p_len, c_len;
	--lim;

	c_len = 0;
	while (c_len < lim && (c = getchar()) != EOF) {
		if (c == '\n')
			while(
				s[(p_len = c_len - 1)] == '\r' ||
				s[p_len] == '\t' ||
				s[p_len] == ' '
			) --c_len;
		s[c_len] = c;
		++c_len;
	}

	s[c_len] = '\0';
}
