#pragma once
#include <iostream>
#include <iomanip>

template <class T>
void getCommand(T& command) {
	std::cout << "Enter a command: ";
	std::cin >> std::setw(1) >> command;

	while (!std::cin.good())
	{
		std::cout << "Error: Faulty input! Try again...\n";
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Enter a command: ";
		std::cin >> std::setw(1) >> command;
	}
	std::cin.clear();
	std::cin.ignore(INT_MAX, '\n');
}
