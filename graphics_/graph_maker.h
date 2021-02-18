#pragma once
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdarg>

class graph_maker {
public:
	explicit graph_maker() = default;
	explicit graph_maker(double a, double b, double c, double f, double t, double s):A_(a), B_(b), C_(c), from_(f), to_(t), step_(s) {};
	
	void set_parametrs();
	void run_loop();
	
private:
	//interface
	bool start_ = false;
	bool pause_ = false;
	bool break_ = false;
	bool info_ = false;
	char grapth_ = false;
	int menu_switcher_ = 0;
	//core
	std::vector<std::string> core_formulas_{
		"f(x) = A * (x * x) + B * x + C",
		"f(x) = A * sin(x) + B * cos(C * x)",
		"f(x) = A * log(B * x)",
		"f(x) = A / (sin(x * x) * B)"
	};
	//data
	int formula_num = 0;
	double A_ = 0.0;
	double B_ = 0.0;
	double C_ = 0.0;
	double from_ = 0.0;
	double to_ = 0.0;
	double step_ = 0.0;
	std::pair<double, double> x_y_ = {0.0, 0.0};
	std::vector<std::pair<double, double>> res_;
};

