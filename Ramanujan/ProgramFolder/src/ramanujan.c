/*
	James Hale
	July 2020
		A simple program to approximate Pi using Ramanujan's series.
  To compile:
    gcc src/ramanujan.c -o bin/ramanujan
  To run:
    ./bin/ramanujan <terms>
    E.g. ./bin/ramanujan 1
    where <terms> is the number of components to expand out to.
*/

/* Imports */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

/* Methods */
double ramanujan(int terms); // Retruns estimate the value of Pi
int factorial(int val); // Returns val factorial

int main(int argc, char** argv)
{
  /*
      Main method: execution stems from here.
    param argc: Argument count
    param argv: Command line argument values
    returns: 0
  */
  // Some print statement
  printf("%s\n", "By Ramanujan's series:");
  // Get command line agrument, convert to int, and pass to method
	printf("pi is about %.50f\n", ramanujan(atoi(argv[1])));
	return 0;
}

double ramanujan(int terms)
{
  /*
      Estimates pi using Ramanujan's series
    param terms: The number of terms to use (1 will yield about 3.141593)
    returns: The approximation of pi
  */
  double pi = 0; // Init the pi approximation
  for(int n = 0; n < terms; n++) // Go through the series calculation
    pi += factorial(4 * n) * (1103 + 26390 * n) / (pow(factorial(n), 4) *
      pow(396, 4 * n));
  // Finalize the calculation, and return
  return 9801 / (2 * sqrt(2) * pi);
}

int factorial(int val)
{
  /*
      Finds the factorial of the argument
    param val: The integer to fine the factorial of
    returns: The factorial evaluation
  */
  int factorial = 1; // Init the return value
  // Go through the iterative calculation
  for(int i = 2; i <= val; i++) factorial *= i;
  return factorial; // Return the value
}
/* End program */
