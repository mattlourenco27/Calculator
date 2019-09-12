/*
 * Created on: June 04 2019
 * Created by: Matthew Lourenco
 * This file calculates the solution(s) to the quadratic formula 
 * Ax^2 + Bx + C = 0
 * given Coefficients A, B, and C
 * 
 * Edited: June 23 2019
 * Changed file to a header file to be implemented in other programs
 *
 * Edited: September 12 2019
 * Changed file back to .c and implemented .h file correctly.
 * This is the implementation file for the quadf module
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include "quadf.h"

//This function calculates the discriminant given A, B, C
static double discriminant(double A, double B, double C) {
	return pow(B,2) - (4 * A * C);
}

//This function calculates the solution to the quadratic formula with two solutions
//'pos' dictates if it uses the plus or minus variant of the formula
static double twoSolution(double A, double B, double C, bool pos) {
	if(pos) {
		return (-B + sqrt(discriminant(A, B, C))) / (2 * A);
	} else {
		return (-B - sqrt(discriminant(A, B, C))) / (2 * A);
	}
}

//This function calculates the solution to the quadratic formula with one solution
static double oneSolution(double A, double B) {
	return -B / (2 * A);
}

//This function calculates the solution to the quadratic formula with two imaginary solutions
//The pointer '*img' points to the value of the imaginary component
static double imaginarySolutions(double A, double B, double C, double *img) {
	*img = sqrt(-discriminant(A, B, C)) / (2 * A);
	return -B / (2 * A); 
}

//This function calculates and prints the quadratic formula
void pquadf(double A, double B, double C) {
	double discr = 0.0;
	
	unsigned const char PLUS_OR_MINUS= 241;
	
	//printf("\nA: %.12lf\nB: %.12lf\nC: %.12lf\n", A, B, C);
	
	discr = discriminant(A, B, C);
	//printf("\nThe discriminant is: %.12lf\n", discr);
	
	if (discr > 0) {
		
		double posSol = twoSolution(A, B, C, true);
		double negSol = twoSolution(A, B, C, false);
		
		printf("\nSolution(+): %.12lf\nSolution(-): %.12lf\n", posSol, negSol);
	} else if (discr == 0) {
		
		double sol = oneSolution(A, B);
		
		printf("\nSingle Solution: %.12lf\n", sol);
	} else {
		
		double imgSol = 0.0;
		double realSol = imaginarySolutions(A, B, C, &imgSol);
		
		printf("\n%.12lf +- i%.12lf\n", realSol, imgSol);
	}
}

//This function calculates the quadratic formula and returns the solutions
// as sol1 and sol2. if the solutions are imaginary then sol1 is the real
// component and sol2 is the imaginary component
void quadf(double A, double B, double C,
		   double *sol1, double *sol2, bool *imag) {
	double discr = 0.0;
	
	//printf("\nA: %.12lf\nB: %.12lf\nC: %.12lf\n", A, B, C);
	
	discr = discriminant(A, B, C);
	//printf("\nThe discriminant is: %.12lf\n", discr);
	
	if (discr > 0) {
		
		*imag = false;
		*sol1 = twoSolution(A, B, C, true);
		*sol2 = twoSolution(A, B, C, false);

	} else if (discr == 0) {
		
		*imag = false;
		*sol1 = oneSolution(A, B);
		*sol2 = *sol1;

	} else {
		
		*imag = true;
		*sol1 = imaginarySolutions(A, B, C, sol2);
		
	}
}