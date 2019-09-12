/* 
 * Created by: Matthew Lourenco
 * Created on: June 25th, 2019
 * This program is a terminal calculator.
 *
 */

#include <stdio.h>
#include <string.h>
#include "quadf.h"

char* EMPTY_LINE = ">> ";
char* COMMAND_LIST = ""
	"-------------------------------------------------------------\n"
	"Commands:\n"
	"+ 'add'      -> adds two real decimal numbers\n"
	"+ 'subtract' -> subtracts two real decimal numbers\n"
	"+ 'multiply' -> multiplies two real decimal numbers\n"
	"+ 'divide'   -> divides two real decimal numbers\n"
    "+ 'quadf'    -> finds the solution to the quadratic formula\n"
	"+ 'help'     -> display a list of commands\n"
    "+ '(q) exit' -> exits the calculator\n"
	"-------------------------------------------------------------";

void close(void);
void openCalc(void);
void getInput(char*, char*);
void get2RealNum(double*, double*);
void get3RealNum(double*, double*, double*);

int main(int argc, char **argv) {
	unsigned int MAX_INPUT_CHARACTERS = 256;
	char input[MAX_INPUT_CHARACTERS + 1];
	double n1, n2, n3; //Three number inputs

	//Switch stout to unbuffered mode to fix scan before inputs
	setvbuf(stdout, 0, _IONBF, 0);
	openCalc();
	
	while (true) {

        getInput(EMPTY_LINE, input);
        
        if (strcmp(strlwr(input), "add") == 0 ||
           strcmp(strlwr(input), "subtract") == 0 ||
           strcmp(strlwr(input), "multiply") == 0 ||
           strcmp(strlwr(input), "divide") == 0) {
        	get2RealNum(&n1, &n2);
        } else if (strcmp(strlwr(input), "quadf") == 0) {
            get3RealNum(&n1, &n2, &n3);
        }
        
        if (strcmp(strlwr(input), "add") == 0) {
        	double sum = n1 + n2;
        	printf("%s%lf", EMPTY_LINE, sum);
        } else if (strcmp(strlwr(input), "subtract") == 0) {
        	double diff = n1 - n2;
        	printf("%s%lf", EMPTY_LINE, diff);
        } else if (strcmp(strlwr(input), "multiply") == 0) {
        	double prod = n1 * n2;
        	printf("%s%lf", EMPTY_LINE, prod);
        } else if (strcmp(strlwr(input), "divide") == 0) {
        	if(n2 == 0) {
                //Catch dvision by zero
        		printf("%sDivision by zero: Nan", EMPTY_LINE);
        	} else {
        		double quotient = n1 / n2;
        		printf("%s%lf", EMPTY_LINE, quotient);
        	}
        } else if (strcmp(strlwr(input), "quadf") == 0) {
            pquadf(n1, n2, n3);
        } else if (strcmp(strlwr(input), "help") == 0) {
        	printf(COMMAND_LIST);
        } else if (strcmp(strlwr(input), "exit") == 0 ||
                   strcmp(strlwr(input), "q") == 0) {
            break;
        } else {
        	printf("%sInvalid Command: Type 'help' for a list of commands", 
                   EMPTY_LINE);
        }
    }
	close();
	return 0;
}

//This funtion runs the closing procedure
void close(void) {
    printf("%sExiting . . .", EMPTY_LINE);
}

//This function prints the openning message
void openCalc(void) {
    printf("Terminal Caculator v1.0: Welcome!\n%s", COMMAND_LIST);
}

//This function displays a message then recieves the response
void getInput(char* message, char* response) {
    printf("\n%s", message);
    gets(response);
}

//This function gets two real number inputs
void get2RealNum(double* n1, double* n2) {
    printf("%sEnter two numbers:\n%s", EMPTY_LINE, EMPTY_LINE);
    scanf("%lf%lf", n1, n2);
    getchar(); //Catches stray newline
}

//This function gets three real number inputs
void get3RealNum(double* n1, double* n2, double* n3) {
    printf("%sEnter three numbers:\n%s", EMPTY_LINE, EMPTY_LINE);
    scanf("%lf%lf%lf", n1, n2, n3);
    getchar(); //Catches stray newline
}