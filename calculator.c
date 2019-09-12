/* 
 * Created by: Matthew Lourenco
 * Created on: June 25th, 2019
 * This program is a terminal calculator.
 *
 */

#include <stdio.h>
#include <string.h>
#include "quadf.h"

char *emptyLine = ">> ";

//This funtion runs the closing procedure
void close(void) {
	printf("\nPress ENTER key to Continue...");
	getchar();
	return;
}

//This function prints the openning message
void openCalc(void) {
	printf("Type a command then give inputs\n"
			"Type 'help' for a list of commands\n");
}

//This function displays a message then recieves the response
void getInput(char *message, char *response) {
	printf(message);
	gets(response);
}

//This function gets the two real number inputs
void getRealNum(double* n1, double* n2) {
	printf("%sEnter two numbers:\n%s", emptyLine, emptyLine);
	scanf("%lf%lf", n1, n2);
	getchar(); //Catches stray newline
}

int main(int argc, char **argv) {
	unsigned int MAX_INPUT_CHARACTERS = 256;
	char input[MAX_INPUT_CHARACTERS + 1];
	double n1, n2; //Two number inputs

	//Switch stout to unbuffered mode to fix scan before inputs
	setvbuf(stdout, 0, _IONBF, 0);
	openCalc();
	getInput(emptyLine, input);

	if(strcmp(strlwr(input), "add") == 0 ||
	   strcmp(strlwr(input), "subtract") == 0 ||
	   strcmp(strlwr(input), "multiply") == 0 ||
	   strcmp(strlwr(input), "divide") == 0) {
		getRealNum(&n1, &n2);
	}

	if (strcmp(strlwr(input), "add") == 0) {
		double sum = n1 + n2;
		printf("%s%lf", emptyLine, sum);
	} else if (strcmp(strlwr(input), "subtract") == 0) {
		double diff = n1 - n2;
		printf("%s%lf", emptyLine, diff);
	} else if (strcmp(strlwr(input), "multiply") == 0) {
		double prod = n1 * n2;
		printf("%s%lf", emptyLine, prod);
	} else if (strcmp(strlwr(input), "divide") == 0) {
		if(n2 == 0) {
			printf("%sDivision by zero: Nan", emptyLine); //Catch dvision by zero
		} else {
			double quotient = n1 / n2;
			printf("%s%lf", emptyLine, quotient);
		}
	} else if (strcmp(strlwr(input), "help") == 0) {
		printf("5");
	} else {
		printf("6");
	}

	close();
	return 0;
}