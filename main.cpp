#include <iostream>
#include "TDynamicStack.h"



int main()
{
	TDynamicStack<int> stack;
	size_t sizeStack = 5;

	std::cout << stack.empty() << ' ' << stack.size() << '\n';

	for (int i = 0; i < sizeStack; ++i)
	{
		std::cout << i + 1 << '\n';
		stack.push(i + 1);
	}

	std::cout << stack.empty() << ' ' << stack.size() << '\n';

	while (!stack.empty())
		std::cout << stack.pop() << '\n';

	try
	{
		std::cout << stack.pop() << '\n';
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << '\n';
	}

	std::cout << stack.empty() << ' ' << stack.size() << '\n';

	



	return 0;
}