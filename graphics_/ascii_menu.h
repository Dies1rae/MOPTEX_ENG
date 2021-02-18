#pragma once
#include <string>
#include <iostream>
#include <iomanip>



void main_menu(const double a = 0.0, const double b = 0.0, const double c = 0.0, const double F = 0.0, const double T = 0.0, const double S = 0.0, const std::string& formula = "Choosen formula:") {
	std::string end_str_tmp;
	for (size_t ptr = formula.size(); ptr < 57; ptr++) {
		end_str_tmp += ' ';
	}
	end_str_tmp.push_back('|');
	system("CLS");
	std::cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << std::endl;
	std::cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|__________________________________________________________|" << std::endl;
	std::cout << "|---A = " << std::setw(4) << a  << "  ---------|-From " << std::setw(4) << F  << "  -----------------------|" << std::endl;
	std::cout << "|---B = " << std::setw(4) << b << "  ---------|-  To " << std::setw(4) << T << "  -----------------------|" << std::endl;
	std::cout << "|---C = " << std::setw(4) << c << "  ---------|-Step " << std::setw(4) << S << "  -----------------------|" << std::endl;
	std::cout << "|----------------------|-----------------------------------|" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~Main controls~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|------------------|----------------------|----------------|" << std::endl;
	std::cout << "|-----1. START-----|-----2. PAUSE---------|---3. BREAK-----|" << std::endl;
	std::cout << "|------------------|----------------------|----------------|" << std::endl;
	std::cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~GRAPHIC~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "| " << formula << end_str_tmp << std::endl;
	
	 
}
