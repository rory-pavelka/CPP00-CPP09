#include "RPN.hpp"

static void throwError(std::string reason)
{
	throw std::runtime_error(reason);
}

static void casePlus(std::stack<int> & stack)
{
	int first, second;

	if (stack.empty())
		throwError("Encountered plus that doesn't have two numbers to add");

	second = stack.top();
	stack.pop();

	if (stack.empty())
		throwError("Encountered plus that doesn't have two numbers to add");

	first = stack.top();
	stack.pop();

	stack.push(first + second);
}

static void caseMinus(std::stack<int> & stack)
{
	int first, second;

	if (stack.empty())
		throwError("Encountered minus that doesn't have two numbers to subtract");

	second = stack.top();
	stack.pop();

	if (stack.empty())
		throwError("Encountered minus that doesn't have two numbers to subtract");

	first = stack.top();
	stack.pop();

	stack.push(first - second);
}

static void caseAsterisk(std::stack<int> & stack)
{
	int first, second;

	if (stack.empty())
		throwError("Encountered asterisk that doesn't have two numbers to multiply");

	second = stack.top();
	stack.pop();

	if (stack.empty())
		throwError("Encountered asterisk that doesn't have two numbers to multiply");

	first = stack.top();
	stack.pop();

	stack.push(first * second);
}

static void caseSlash(std::stack<int> & stack)
{
	int first, second;

	if (stack.empty())
		throwError("Encountered slash that doesn't have two numbers to divide");

	second = stack.top();
	if (second == 0)
		throwError("Division by zero");
	stack.pop();

	if (stack.empty())
		throwError("Encountered slash that doesn't have two numbers to divide");

	first = stack.top();
	stack.pop();

	stack.push(first / second);
}

static void caseNumber(std::stack<int> & stack, int number)
{
	if (number >= 0 && number <= 9)
		stack.push(number);
	else
		throwError("Encountered char that is neither number nor operator");
}

void runRPN(const char* argv1)
{
	std::stack<int> stack;
	bool isFirst = true;

	for (int i = 0; argv1[i]; i++)
	{
		if (!isFirst && argv1[i] != ' ')
			throwError("Found a token that is more than one character long");
		while (argv1[i] == ' ')
			i++;
		if (!argv1[i])
			break;

		switch (argv1[i])
		{
		case ('+'):
			casePlus(stack);
			break;
		case ('-'):
			caseMinus(stack);
			break;
		case ('*'):
			caseAsterisk(stack);
			break;
		case ('/'):
			caseSlash(stack);
			break;
		default:
			caseNumber(stack, argv1[i] - '0');
			break;
		}
		isFirst = false;
	}

	if (!stack.empty())
	{
		int result = stack.top();
		stack.pop();
		if (stack.empty())
		{
			std::cout << result << std::endl;
			return;
		}
	}
	throwError("Numbers were left in the stack in the end");
}
