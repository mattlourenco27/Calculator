/* 
 * Created by: Matthew Lourenco
 * Created on: June 25th, 2019
 * This program is a terminal calculator.
 *
 */

#include <stdio.h>
#include <string.h>
#include "quadf.h"

//This function displays a message then recieves the response
void *getInput(char *message, char *response) {
	printf(message);
	gets(response);
}

int main(int argc, char **argv) {
	unsigned int MAX_INPUT_CHARACTERS = 256;
	char input[MAX_INPUT_CHARACTERS + 1];

	//Switch stout to unbuffered mode to fix scan before inputs
	setvbuf(stdout, 0, _IONBF, 0);

	getInput(">> ", input);

	printf("%s", input);

}