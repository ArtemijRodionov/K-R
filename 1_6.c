#include <stdio.h>

const int IN = 1;
const int OUT = 0;

void count_numbers_space_other()
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;
	for (i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) 
		if (c >= '0' && c <= '9')
			++ndigit[c-'0'];
		else if (c == ' ' || c == '\n' || c == '\t')
			++nwhite;
		else
			++nother;

	printf("digits:\n");
	for (i = 0; i < 10; ++i)
		printf(" - %d: %d\n", i, ndigit[i]);
	printf("white space:\n - %d\nother:\n - %d\n", nwhite, nother);
}

void get_word_lens()
{
	int c, p, i;

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (!(p == ' ' || p == '\n' || p == '\t'))
	 			printf(" %d\n", i);
			i = 0;
		} else {
			++i;
			putchar(c);
		}

 		p = c;
 	}
}

void get_char_frequencies()
{
	const int LAST = '~'; 

	int c, i, characters[LAST];

	for (i = 0; i < LAST; ++i)
		characters[i] = 0;

	while ((c = getchar()) != EOF)
		if (c > ' ' && c <= '~')
			++characters[c];

	printf("|-----------|--------|\n");
	printf("| Character | Number |\n");
	printf("|-----------|--------|\n");
	for (i = 0; i < LAST; ++i)
		if (characters[i] > 0)
			printf("| %9c | %6d |\n", i, characters[i]);
}

int main(int argc, char const *argv[])
{
	// count_numbers_space_other();
	// get_word_lens();
	get_char_frequencies();
	return 0;
}