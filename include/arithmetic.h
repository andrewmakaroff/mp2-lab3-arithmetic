// объ€вление функций и классов дл€ вычислени€ арифметических выражений

#pragma once

#include "stack.h"
#include <string>
#include <windows.h>
#include <vector>

class arithmetic {
public:
	arithmetic(const std::string& _str) : expr(_str), copy_expr(_str) {};

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	std::string	delete_spaces();

	std::string	convert();
	double compute(const std::string&);
	std::vector<std::string> is_expression_is_correct(const std::string&);
	size_t letters_counter(const std::string&);

	static int operators_priority(char operators);
	static bool is_digit(char elem);
	static bool	is_letter(char elem);
	static bool	is_operator(char op);
	static bool is_dot(char elem);

	void print() {
		if (is_expression_is_correct(copy_expr).empty()) {
			std::string string_after_transformig;
			string_after_transformig = convert();

			SetConsoleTextAttribute(hConsole, 14);
			std::cout << "[~] Transforming [ " << expr << " ] " << "\t-->\t[ " << string_after_transformig << "]" << '\n';

			SetConsoleTextAttribute(hConsole, 10);
			if (letters_counter(copy_expr) == 0)
				std::cout << "\t[+] Result afrer calculations = " << compute(string_after_transformig) << '\n';
		}
		else std::cout << is_expression_is_correct(copy_expr).front();
		SetConsoleTextAttribute(hConsole, 15);
	}
private:
	std::string expr;
	std::string copy_expr;
};