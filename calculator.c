/* 
 * Created by: Matthew Lourenco
 * Created on: June 25th, 2019
 * This program is a terminal calculator.
 *
 */

#include <stdio.h>
#include <string.h>
#include "quadf.h"

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

int main(int argc, char **argv) {
	unsigned int MAX_INPUT_CHARACTERS = 256;
	char input[MAX_INPUT_CHARACTERS + 1];
	char *emptyLine = ">> ";

	//Switch stout to unbuffered mode to fix scan before inputs
	setvbuf(stdout, 0, _IONBF, 0);
	openCalc();
	getInput(emptyLine, input);

	if (strcmp(strlwr(input), "add") == 0) {
		printf("1");
	} else if (strcmp(strlwr(input), "subtract") == 0) {
		printf("2");
	} else if (strcmp(strlwr(input), "multiply") == 0) {
		printf("3");
	} else if (strcmp(strlwr(input), "divide") == 0) {
		printf("4");
	} else if (strcmp(strlwr(input), "help") == 0) {
		printf("5");
	} else {
		printf("6");
	}

	close();
	return 0;
}