#pragma once
#include <string>
#include <iostream>
#include <iomanip>



void main_menu(const double proc = 0.0, const double a = 0.0, const double b = 0.0, const double c = 0.0, const double F = 0.0, const double T = 0.0, const double S = 0.0, const std::string& formula = "Choosen formula:", const std::vector<std::string>& formulas = {}) {
	std::string end_str_tmp;
	for (size_t ptr = formula.size(); ptr < 57; ptr++) {
		end_str_tmp += ' ';
	}
	end_str_tmp.push_back(']');
	system("CLS");
	std::cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << std::endl;
	std::cout << "|@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@|                      FORMULAS                  |" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| 1. " << formulas[0] << std::setw(15) << " |"  << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~| 2. " << formulas[1] << std::setw(11) << " |" << std::endl;
	std::cout << "|__________________________________________________________| 3. " << formulas[2] << std::setw(24) << " |" << std::endl;
	std::cout << "|---A = " << std::setw(4) << a  << "  ---------|-From " << std::setw(4) << F  << "  -----------------------| 4. " << formulas[3] << std::setw(18) << " |" << std::endl;
	std::cout << "|---B = " << std::setw(4) << b << "  ---------|-  To " << std::setw(4) << T << "  -----------------------| 5. " << formulas[4] << std::setw(24) << " |" << std::endl;
	std::cout << "|---C = " << std::setw(4) << c << "  ---------|-Step " << std::setw(4) << S << "  -----------------------|                                                |" << std::endl;
	std::cout << "|----------------------|-----------------------------------|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~Main controls~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|-------------|----------|----------|---------|------------|" << std::endl;
	std::cout << "|----1. START-|-2. PAUSE-|-3. BREAK-|-4. INFO-|-5. QUIT----|" << std::endl;
	std::cout << "|-------------|----------|----------|---------|------------|" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|---Process bar: " << proc << " % " << std::setw(39) << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~GRAPHIC~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
	std::cout << "[ " << formula << end_str_tmp << std::endl;
	
	 
}


void Info_menu(const std::vector<std::pair<double, double>> coords) {
	if (!coords.empty()) {
		std::cout << "[~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~]" << std::endl;
		std::cout << "|@@@@@@@@@@@@@@@@@@@       COORDS        @@@@@@@@@@@@@@@@@@@@@@@@|" << std::endl;
		std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
		std::cout << "|________X___________________________Y___________________________|" << std::endl;
		for (const auto c : coords) {
			std::cout << "|---    " << std::setw(4) << c.first << "  -----------     " << std::setw(10) << c.second << "  -----------------------|" << std::endl;
		}
		std::cout << "|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|" << std::endl;
		system("PAUSE");
	}
}