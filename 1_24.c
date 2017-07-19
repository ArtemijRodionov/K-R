/**
* Write a program to check a C program for rudimentary syntax errors like
* unmatched parentheses, brackets and braces. Don't forget about quotes, both
* single and double, escape sequences, and comments. (This program is hard if
* you do it in full generality.)
**/ 

#include <stdio.h>

#define OPEN 1
#define CLOSE 0

int should_match(int single_quotes, int double_quotes, int multiline_comments) {
	return !(single_quotes || double_quotes || multiline_comments);
}

int main(int argc, char const *argv[])
{
	char c, p;

	int parentheses = CLOSE;
	int brackets = CLOSE;
	int braces = CLOSE;
	int single_quotes = CLOSE;
	int double_quotes = CLOSE;
	int multiline_comments = CLOSE;

	while ((c = getchar()) != EOF) {
		if (c == '*' && p == '/')
			multiline_comments = OPEN;
		else if (c == '/' && p == '*')
			multiline_comments = CLOSE;

		if (c == '\'' && p != '\\' || multiline_comments) {
			if (single_quotes)
				single_quotes = CLOSE;
			else
				single_quotes = OPEN;
		}

		if (c == '\"' && p != '\\' || multiline_comments)
			if (double_quotes)
				double_quotes = CLOSE;
			else
				double_quotes = OPEN;

		if (c == '{' && should_match(single_quotes, double_quotes, multiline_comments))
			parentheses = OPEN;
		else if (c == '(' && should_match(single_quotes, double_quotes, multiline_comments))
			brackets = OPEN;
		else if (c == '[' && should_match(single_quotes, double_quotes, multiline_comments))
			braces = OPEN;
		else if (c == '}'  && should_match(single_quotes, double_quotes, multiline_comments))
			parentheses = CLOSE;
		else if (c == ')'  && should_match(single_quotes, double_quotes, multiline_comments))
			brackets = CLOSE;
		else if (c == ']'  && should_match(single_quotes, double_quotes, multiline_comments))
			braces = CLOSE;

		p = c;
	}

	if (parentheses || brackets || braces || single_quotes || double_quotes || multiline_comments) {
		printf("parentheses: %d\n", parentheses);
		printf("brackets: %d\n", brackets);
		printf("braces: %d\n", braces);
		printf("single_quotes: %d\n", single_quotes);
		printf("double_quotes: %d\n", double_quotes);
		printf("multiline_comments: %d\n", multiline_comments);

		printf("Syntax appears to be incorrect.\n");
	}

	return 0;
}
