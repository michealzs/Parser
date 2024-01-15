

#include <cstdio>
#include <string>
#include <queue>
#include <array>
using namespace std;

#include "listing.h"

static int lineNumber;

//static string error = ""; 

static int totalErrors = 0;

static array<int, 3> errorCounts = {0, 0, 0}; // {lexical, syntactic, semantic}
static queue<string> errorMessages;


//static void displayErrors(); 

void firstLine()
{
	lineNumber = 1;
	printf("\n%4d  ",lineNumber);
}

void nextLine()
{
	displayErrors();
	lineNumber++;
	printf("%4d  ",lineNumber);
}

int lastLine()
{
	printf("\r");
	displayErrors();
	printf("     \n");

	if (totalErrors > 0) {
        printf("Total Errors: %d\n", totalErrors);
        printf("Lexical Errors: %d, Syntactic Errors: %d, Semantic Errors: %d\n",
               errorCounts[0], errorCounts[1], errorCounts[2]);
    } else {
        printf("Compiled Successfully\n");
    }

	return totalErrors;
}
    
void appendError(ErrorCategories errorCategory, string message)
{
	string messages[] = { "Lexical Error, Invalid Character ", "",
		"Semantic Error, ", "Semantic Error, Duplicate ",
		"Semantic Error, Undeclared " };

	errorMessages.push(messages[errorCategory] + message);
	totalErrors++;
	errorCounts[errorCategory]++;
	//error = messages[errorCategory] + message;
	
}

void displayErrors()
{
	while (!errorMessages.empty()) {
    	printf("%s\n", errorMessages.front().c_str());
        errorMessages.pop();
    }
	/*
	if (error != "")
		printf("%s\n", error.c_str());
	error = "";
	*/
}
