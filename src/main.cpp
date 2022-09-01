////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"
#include <cstring>

std::string convertToString(char* a, int size)
{
	int i;
	std::string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

int main() 
{
	// exit flag
	bool exit = false;

	// command flag
	bool command = false;
	
	// array of commands
	const char help[5] = "help";
	const char history[8] = "history";
	const char exitCmd[5] = "exit";
	const char* commands[4] = { help, history, exitCmd, "\0"};
	
	// Loop until quit
	while (!exit)
	{
		// Take user input
		char expression[100];
		std::cout << "Enter an expression: ";
		std::cin.getline(expression, 100);
		
		// check if expression is a command
		std::string cmdCheck = convertToString(expression, sizeof(expression));
		for (const char* i = *commands; i != "\0"; i++)
		{
			// Compare string i with expression to see if they match
			if (std::strcmp(expression, i) == 0)
			{
				command = true;
				// switch case to run correct command based on i
				switch (i[1])
				{
				case 'x':
					std::cout << "Stopping Calculator";
					exit = true;
					break;
				}
				break;
			}
		}

		if (!command)
			// Evaluate expression
			Evaluate(expression);

		command = false;
	}
	
}