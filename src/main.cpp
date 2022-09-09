////////////////////////////////////////////////////////////////////////////
/**
 *  @file   main.cpp
 *  @date   Fri April 16 2021
 *  @brief  Entry Point of Calculator
 */
 ////////////////////////////////////////////////////////////////////////////
#include "Calculator.h"

#include <fstream>
#include <cstring>
#include <iostream>
#include <list>

// Helper Functions
std::string convertToString(char* a, int size)
{
	int i;
	std::string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

void loadHistory(std::list<std::string>& data, std::string path)
{
	std::ifstream input(path);

	if (input)
	{
		for (int i = 0; i < 10; i++)
		{
			std::string buffer;
			input >> buffer;
			if (buffer != "")
				data.push_front(buffer);
		}

	}
	input.close();
}

void saveHistory(std::list<std::string> data, std::string path)
{
	// Create out file stream
	std::ofstream output(path);

	// If file stream is open, write data to it
	if (output)
	{
		// Write Map data per line in binary
		for (std::list<std::string>::iterator i = data.begin(); i != data.end(); i++)
		{
			output << *i << std::endl;
		}
	}
	output.close();
}

int main()
{
	// file io path
	std::string path(getenv("HOME"));
	path += "/Data/history.txt";

	// exit flag
	bool exit = false;

	// command flag
	bool command = false;

	// array of commands
	const char help[5] = "help";
	const char historyCmd[8] = "history";
	const char exitCmd[5] = "exit";
	std::list<std::string> commands = { help, historyCmd, exitCmd, "\0" };

	// Map to store key value pairs of expressions/commands used and system response
	std::list<std::string> history;

	// Check if there is a Data folder
	loadHistory(history, path);

	// Loop until quit
	while (!exit)
	{
		// Take user input
		char expression[100];
		std::cout << "Enter an expression: ";
		std::cin.getline(expression, 100);

		// check if expression is a command
		std::string cmdCheck = convertToString(expression, sizeof(expression));
		if (!std::string::npos != cmdCheck.find_first_of("0123456789"))
		{
			for (std::list<std::string>::iterator i = commands.begin(); i != commands.end(); i++)
			{
				// Compare string i with expression to see if they match
				if (std::strcmp(expression, (*i).c_str()) == 0)
				{
					command = true;
					// switch case to run correct command based on i
					switch ((*i).c_str()[1])
					{
					case 'x':
						std::cout << "Stopping Calculator";
						exit = true;
						break;
					case 'e':
						std::cout << "Commands:" << std::endl;

						// For each command in commands print command
						for (std::string cmd : commands)
						{
							std::cout << cmd << std::endl;
						}
						break;
					case 'i':
						std::cout << "History:" << std::endl;
						for (std::list<std::string>::iterator j = history.begin(); j != history.end(); j++)
						{
							std::cout << (*j) << std::endl;
						}
						break;
					}
					break;
				}
			}
			std::cout << "Invalid Command \n" << std::endl;
			continue;
		}

		double result;

		if (!command)
			// Evaluate expression
			result = Evaluate(expression);

		// Copy expression into string
		std::string input = expression;
		
		// Convert result to string
		std::string output = std::to_string(result);

		if (!output.empty())
		{
			std::cout << result << std::endl;
			history.push_front(input);
			if (history.size() > 10)
				history.pop_back();
		}
		else if (command)
		{
			history.push_front(input);
			if (history.size() > 10)
				history.pop_back();
		}

		command = false;
		std::cout << std::endl;
	}

	saveHistory(history, path);
}