#include <stdio.h>

/*
Usage:
	cat file_name.txt | a.out
*/

void symbol_counter()
{
	int c;
	int p;

	int t = 0; // \t tab ansii code 9
	int nl = 0; // \n newline ansii code 8
	int bl = 0; // \n\n blank lines
	int s = 0; // spaces ansii 32

	while ((c = getchar()) != EOF) {
		switch (c)
		{
			case '\n':
				if (p == '\n') ++bl;
				++nl;
			case '\t':
				++t;
			case 32:
				++s;
		}

		p = c;

	}

	printf("%8s %s\n", "Number", "Symbol");
	printf("%8d %s\n", nl, "New lines");
	printf("%8d %s\n", t, "Tabs");
	printf("%8d %s\n", bl, "Blanks");
	printf("%8d %s\n", s, "Spaces");
}

void remove_multiple_blanks()
{
	int c, p;

	while ((c = getchar()) != EOF)
	{
		if (c == '\n' && p == '\n') continue;
		p = c;
		putchar(c);
	}
}

void appear_tabs_and_backslashes()
{
	int c;

	while((c = getchar()) != EOF)
	{
		switch (c) {
			case '\t':
				printf("%s", "\\t");
			case '\b':
				printf("%s", "\\b");
			case '\\':
				printf("%s", "\\");
				break;
			default:
				putchar(c);
		} 
	}

}

int main(int argc, char const *argv[])
{
	// symbol_counter();
	// remove_multiple_blanks();
	appear_tabs_and_backslashes();

	return 0;
}
