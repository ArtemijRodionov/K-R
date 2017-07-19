#include <stdio.h>

void print_horizontal_delimetre() {
	printf("%s\n", "-----------------------");
}

int main() 
{
	float fahr, celsius;
	float lower, upper, step;

	lower = -30;
	upper = 50;
	step = 5;

	celsius = lower;
	print_horizontal_delimetre();
	printf("|%8s | %10s|\n", "Celsius", "Fahrenheit");
	while (celsius <= upper) {
		fahr = celsius * 9.0 / 5.0 + 32.0;
		print_horizontal_delimetre();
		printf("|%8.1f | %10.0f|\n", celsius, fahr);
		celsius = celsius + step;
	}

	print_horizontal_delimetre();


	return 0;

}