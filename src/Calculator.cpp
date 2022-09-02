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

	// Scan expression for values
	sscanf(expression, "%lf %c %lf", &a, &op, &b);

	// Switch statement to decide which operation to perform
	switch (op)
	{
	case '+':
		result = Add(a, b);
		break;
	case '-':
		result = Subtract(a, b);
		break;
	case '*':
		result = Multiply(a, b);
		break;
	case '/':
		result = Divide(a, b);
		break;
	default:
		std::cout << "Invalid operator" << std::endl;
		result = NULL;
		break;
	}

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