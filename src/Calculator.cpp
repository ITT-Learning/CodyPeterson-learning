////////////////////////////////////////////////////////////////////////////
/**
 *  @file   Calculator.cpp
 *  @date   Fri April 16 2021
 *  @brief  Funtions that support main.cpp
 */
////////////////////////////////////////////////////////////////////////////

#include "Calculator.h"

// Evaluate method, decides which operation to perform
void Evaluate(char* expression)
{
	// Declare variables
	double a, b;
	char op;

	// Scan expression for values
	sscanf(expression, "%lf %c %lf", &a, &op, &b);

	// Switch statement to decide which operation to perform
	switch (op)
	{
	case '+':
		std::cout << Add(a, b) << std::endl;
		break;
	case '-':
		std::cout << Subtract(a, b) << std::endl;
		break;
	case '*':
		std::cout << Multiply(a, b) << std::endl;
		break;
	case '/':
		std::cout << Divide(a, b) << std::endl;
		break;
	default:
		std::cout << "Invalid operator" << std::endl;
		break;
	}
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