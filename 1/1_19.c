/**
* Write a function `reverse(s)` that reverses the character string `s`.
* Use it to write a program that reverses its input a line at a time.
**/

#include <stdio.h>

#define MAXLINE 1000


void reverse(char s[]);


int main(int argc, char const *argv[])
{
	int i = 0;
	char c, buffer[MAXLINE];

	while ((c = getchar()) != EOF && i < (MAXLINE-1))
		if (c != '\n') {
			buffer[i] = c;
			++i;
		}
		else {
			buffer[i] = '\0';
			reverse(buffer);
			printf("%s\n", buffer);
			i = 0;
		};
	
	return 0;
}

void reverse(char s[])
{
	int i, j, tmp;

	if (s[0] == '\0')
		return;

	for (i = 0; s[i] != '\0'; ++i); // get string length
	for (j = i - 1, i = 0; i <= j; ++i, --j) { // make swap
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;

	}
}
