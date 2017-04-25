#include <stdio.h>

#define MAXLINE 1000
#define RULER 79

/**
* Exercise 1-17. Write a program to print all input lines that are
* longer than 80 characters. 
**/

int	getline_(char line[], int maxline);
int append(char to[], char from[], int last);

int main(int argc, char const *argv[])
{
	int len, last;
	char lines[MAXLINE], longer[MAXLINE];

	last = 0;
	while ((len = getline_(longer, MAXLINE)) > 0)
		if (len > RULER)
			last = append(lines, longer, last);
	
	for(int i = 0; last > i; ++i)
		putchar(lines[i]);

	return 0;
}

int getline_(char s[], int lim)
{
	int c;
	int i = 0;

	--lim;
	while (i < lim && (c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		++i;
	}

	if (c == '\n') {
		s[i] = c;
		++i;
	}

	s[i] = '\0';

	return i;
}

int append(char to[], char from[], int last)
{
	for (int i = 0; (to[last] = from[i]) != '\0'; ++i, ++last);
	return last;
}
