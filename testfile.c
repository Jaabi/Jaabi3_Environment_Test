/*
	Environment Test

	Tests various features of the current environment.

	Usage:
		<TODO>
*/

//Includes
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//Globals
int indentLevel = 0;

//Declarations
int printWrapper(const char* fmt, ...);
void printHeadingType(int type, int length, char* header);
void printRepeat(int times, int length, char* pattern);
void flushPrompt(int lines);
int testCompiling();


//- - - -
// Main
//- - - -
int main(int argc, char** argv) {

	//Flush the command prompt
	flushPrompt(100);

	//Testing GCC
	int compReturn = testCompiling();

	if(compReturn != 0) {

	}


	//Give user a clean prompt line
	printRepeat(1, 1, "\n");

	//Everything is fine, so exit! c:
	return 0;
}

//- - - - - - - -
// Aux Functions
//- - - - - - - -

/* testCompiling
	Tests whether this can compile

	Inputs
		- None

	Outputs
		- None

	Side Effects
		- Text printed to the prompt stating success or errors
*/
int testCompiling() {
	indentLevel++;

	int status = 0;

	//Print the top-level heading
	indentLevel--;
	printHeadingType(1, 14, "Compiling Test");
	printWrapper("\n");
	indentLevel++;

	//Print the success of compilation!
	printHeadingType(2, 17, "Compiling Success");

	indentLevel--;
	return status;
}

//- - - - - - - - - -
// Helper Functions
//- - - - - - - - - -

/* printWrapper
	Prints while taking into account the indentation level

	NOTE: From tutorial
		https://bytes.com/topic/c/answers/220856-printf-wrapper

	Inputs
		- char* fmt: The string to print

	Outputs
		- Return value of vprintf(...)

	Side Effects
		- Prints the given string  with indentation
*/
int printWrapper(const char* fmt, ...) {
	int indentCounter = indentLevel;
	while(indentCounter > 0) {
		printf("\t");

		indentCounter--;
	}

	//Call printf proper
	int retval = 0;
	va_list args;
	va_start(args, fmt);

	retval = vprintf(fmt, args);

	va_end(args);

	return retval;
}

/* printHeadingType
	Convenience function. Select between header types.

	Inputs
		- int type: The type of heading to print
		- int length: The length of the string
		- char* string: The string to print

	Outputs
		- None

	Side Effects
		- Prints the appropriate heading
*/
void printHeadingType(int type, int length, char* header) {

	//Choose the border type
	char* borderChar = (char*) malloc(2);
	borderChar[0] = '\0';
	borderChar[1] = '\0';
	
	if(type == 1) {
		borderChar[0] = '=';
	} else if(type == 2) {
		borderChar[0] = '-';
	}

	//Print the Header
	//Top border
	printWrapper("");
	printRepeat(length + 2, 1, borderChar);
	printf("\n");

	//Header proper
	printWrapper(" %s ", header);
	printf("\n");

	//Bottom border
	printWrapper("");
	printRepeat(length + 2, 1, borderChar);
	printf("\n");

	//Free the border char
	free(borderChar);
}

/* printRepeat
	Repeatedly prints the given pattern.

	Inputs
		- int times: How many times to repeat the pattern
		- int length: The length of the pattern (minus '\0')
		- char* pattern: char string

	Outputs
		- None

	Side Effects
		- Prints the given pattern a set amount of times
*/
void printRepeat(int times, int length, char* pattern) {

	if(times < 0 || length < 0 || pattern == NULL) {
		//Find a way to put error log
		return;
	}

	while(times > 0) {
		for(int i = 0; i < length; i++) {
			printf("%c", pattern[i]);
		}

		times--;
	}
}

/* flushPrompt
	Flushes the prompt so as to give a clean screen

	Inputs
		- int lines: How many blank lines to print

	Outputs
		- None

	Side Effects
		- lines amount of blank lines are printed to the prompt
*/
void flushPrompt(int lines) {
	if(lines <= 0) {
		return;
	}

	printRepeat(lines, 1, "\n");
}
