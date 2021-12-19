// реализация пользовательского приложения

#include <iostream>
#include <vector>
#include <conio.h>
#include "arithmetic.h"

void calculate();
void simple_calculating_tests();
void simple_error_tests();
void clear_console();


void user_interface() {
	char choice;
	std::cout << "[!] If you want to enter an expression please type '1' \n";
	std::cout << "[!] If you want to see default calculating examples please type '2' \n";
	std::cout << "[!] If you want to see default error examples please type '3' \n";
	std::cout << "[!] If you want to reset console please type '4' \n";
	std::cout << "[!] If you want to quit calculator please type '5' \n";
	std::cout << "[+] Your choise - ";
	std::cin >> choice;
	std::cout << '\n';
	switch (choice) {
	case '1':
		calculate();
		break;
	case '2':
		simple_calculating_tests();
		break;
	case '3':
		simple_error_tests();
		break;
	case '4':
		clear_console();
		break;
	case '5':
		exit(0);
		break;
	default:
		std::cout << "[!] Incorrect symbol \n";
		std::cout << "\t[~] exiting...";
		Sleep(300);
		exit(0);
	}
}

void calculate() {
	std::string entered_expression;
	std::cout << "[+] Please enter your expression:  ";
	std::getline(std::cin >> std::ws, entered_expression);
	std::cout << "\n\n";
	arithmetic calculate(entered_expression);
	SetConsoleTextAttribute(calculate.hConsole, 15);
	std::cout << "[!] The expression is [ " << calculate.delete_spaces() << " ]" << '\n';
	calculate.print();
	std::cout << '\n';
	user_interface();
}

void clear_console() {
	system("cls");
	user_interface();
}

void simple_calculating_tests() {
	std::vector<std::string> simple_tests_c = {
		{	"1*2+3"											},
		{	"1*2+3"											},
		{	"(1+2)*(3/4)"									},
		{	"1*(2*3+4*5)+6"									},
		{	"3.0+1"											},
		{	"-1+2"											},
		{	"2+ ( -1)"										},
		{	"- 1 + ( -1)"									},
		{	"1                            +  (-2)"			},
		{	"4.1+3.2"										},
		{	"10/(-5)"										},
		{	"11*(-2)"										},
		{	"3-2"											},
		{	"6/2"											},
		{	"50-100"										},
		{	"1/10"											},
		{	"(1+2)-(3-2)"									},
	};
	while (!simple_tests_c.empty()) {
		arithmetic tests(simple_tests_c.front());
		SetConsoleTextAttribute(tests.hConsole, 15);
		std::cout << "[!] The expression is [ " << tests.delete_spaces() << " ]" << '\n';
		tests.print();
		simple_tests_c.erase(simple_tests_c.begin());
	}
	std::cout << '\n';
	user_interface();
}

void simple_error_tests() {
	std::vector<arithmetic> simple_tests_m = {
		{	"1+a-"											},
		{	")1+a"											},
		{	".1+a"											},
		{	"+1+a"											},
		{	"!a+2" 											},
		{	"1++a"											},
		{	"1+a=" 											},
		{	"1+.a"											},
		{	"1.+a"											},
		{	"1+2+"											},
		{	"1+2("											},
		{	"1+2++" 										},
		{	"1+2+(" 										},
		{	"1++a"  										},
		{	"((1+3)"										},
		{	"1(+3)" 										},
		{	"1+3+"  										},
		{	"1+3."  										},
	};
	while (!simple_tests_m.empty()) {
		arithmetic tests(simple_tests_m.front());
		SetConsoleTextAttribute(tests.hConsole, 15);
		std::cout << "[!] The expression is [ " << tests.delete_spaces() << " ]" << '\n';
		tests.print();
		simple_tests_m.erase(simple_tests_m.begin());
	}
	std::cout << '\n';
	user_interface();
}


void main()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	std::cout << "[!] Arithmetical expressions\n";
	user_interface();

	system("pause");
}
