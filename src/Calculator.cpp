////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

// Evaluate method, decides which operation to perform
double Evaluate(char* expression)
{
	// Declare variables
	double result;
	double a, b;
	char op;
	
	int parenDepth = 0;
	int size = 0;
	int firstParen = NULL;
	
	// Scan expression for parenthesis
	for (const char* i = expression; *i != '\0'; i++)
	{
		if (*i == '(')
		{
			if (parenDepth == 0)
				firstParen = (i - expression) + 1;
			parenDepth++;
		}
		else if (*i == ')')
		{
			--parenDepth;
			if (parenDepth > 0)
				continue;
			break;
		}
		
		if (parenDepth > 0)
		{
			size++;
		}
	}
	
	if (firstParen != NULL)
	{
		// Convert expression to string
		std::string input = expression;

		// Get values between firstParen and parenMatch
		std::string paren = input.substr(firstParen, size);
		
		char value[size];
		std::strcpy(value, paren.c_str());

		// Evaluate expression inside parenthesis
		double pValue = Evaluate(value); //12000.549
		std::string pVal = std::to_string(pValue);
		
		input.replace(firstParen, size, pVal);

		// Remove extra parenthesis
		std::string temp;
		for (int i = 0; i < input.length(); i++)
		{
			if (!(input[i] == '(' || input[i] == ')'))
				temp += std::string(1, input[i]);
		}
		
		// Clear input
		input.clear();
		
		// Copy temp to input
		input = temp;
		
		std::strcpy(expression, input.c_str());
	}
	
	// Order of operations
		// 1. Multiplication and Division
		
		// Scan expression for multiplication and division
	for (const char* i = expression; *i != '\0'; i++)
	{
		if (*i == '*' || *i == '/')
		{
			const char* before;
			// Get values before and after operator
			for (const char* j = i; j != expression; j--)
			{
				if (*j == '+' || *j == '-')
				{
					while (*j == ' ' || *j == '+' || *j == '-')
						j++;
					before = j;
					break;
				}
				
				if ((j - 1) == expression)
					before = expression;
			}
			a = atof(before);
			b = atof(i + 1);
			op = *i;

			// Perform operation
			if (op == '*')
				result = Multiply(a, b);
			else if (op == '/')
				result = Divide(a, b);

			// Convert result to string
			std::string res = std::to_string(result);

			// Replace expression with result
			std::string input = expression;
			input.replace(before - expression, i - expression + 1, res);

			// Clear expression
			//expression = NULL;

			// Copy input to expression
			std::strcpy(expression, input.c_str());
		}
		
	}
	
		// 2. Addition and Subraction
	
		// Scan expression for addition and subtraction
	for (const char* i = expression; *i != '\0'; i++)
	{
		if (*i == '+' || *i == '-')
		{
			// Get values before and after operator
			a = atof(expression);
			b = atof(i + 1);
			op = *i;

			// Perform operation
			if (op == '+')
				result = Add(a, b);
			else if (op == '-')
				result = Subtract(a, b);

			// Convert result to string
			std::string res = std::to_string(result);

			// Replace expression with result
			std::string input = expression;
			input.replace(0, i - expression + 1, res);

			// Clear expression
			//expression = NULL;

			// Copy input to expression
			std::strcpy(expression, input.c_str());
		}

	}
		
	
	//// Scan expression for values
	//sscanf(expression, "%lf %c %lf", &a, &op, &b);

	//// Switch statement to decide which operation to perform
	//switch (op)
	//{
	//case '+':
	//	result = Add(a, b);
	//	break;
	//case '-':
	//	result = Subtract(a, b);
	//	break;
	//case '*':
	//	result = Multiply(a, b);
	//	break;
	//case '/':
	//	result = Divide(a, b);
	//	break;
	//default:
	//	std::cout << "Invalid operator" << std::endl;
	//	result = NULL;
	//	break;
	//}
	
	return result;
}

// Add method, returns sum of two numbers as double
double Add(double a, double b)
{
	return a + b;
}

// Subtract method, returns difference of two numbers as double
double Subtract(double a, double b)
{
	return a - b;
}

// Multiply method, returns product of two numbers as double
double Multiply(double a, double b)
{
	return a * b;
}

// Divide method, returns quotient of two numbers as double
double Divide(double a, double b)
{
	return a / b;
}