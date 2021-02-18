#include "graph_maker.h"
#include "graph.h"
#include "ascii_menu.h"

void graph_maker::set_parametrs() {
	std::cout << "Please set parametrs for field A B C and FROM TO STEP" << std::endl;
	std::cin >> this->A_ >> this->B_ >> this->C_ >> this->from_ >> this->to_ >> this->step_;
}

void graph_maker::run_loop() {
	gsch::Drawings<60, 30> default_can;
	default_can.axes();

	main_menu();
	this->set_parametrs();

	std::cout << "Choose formula: " << std::endl;
	for (size_t ptr = 0; ptr < this->core_formulas_.size(); ptr ++) {
		std::cout << ptr + 1 << ": " << this->core_formulas_[ptr] << std::endl;
	}
	std::cin >> this->formula_num;
	
	std::string formula_tmp = "Choosen formula: " + this->core_formulas_[this->formula_num - 1];
	main_menu(this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp);
	std::cin >> this->menu_switcher_;

	switch (this->formula_num) {
	case 1:
		this->start_ = true;
		break;

	case 2:
		this->start_ = false;
		this->pause_ = true;
		break;
	
	case 3:
		this->break_ = true;
		break;

	default:
		break;
	}
	

	switch (this->formula_num) {
	case 1:
		try{
			for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
				this->x_y_.second = (this->A_ * std::pow(this->x_y_.first, 2)) + (this->B_ * this->x_y_.first) + this->C_;
				this->res_.push_back({ this->x_y_.first, this->x_y_.second });
				for (const auto& point : this->res_) {
					default_can.plot(this->x_y_.first, this->x_y_.second);
				}
				main_menu(this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp);
				std::cout << default_can;
				std::chrono::milliseconds timespan(500);
				std::this_thread::sleep_for(timespan);
			}
		}
		catch (...) {
			std::cerr << "Some data error" << std::endl;
		} break;

	case 2:
		try{
			for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
				this->x_y_.second = (this->A_ * sin(this->x_y_.first)) + (this->B_ * cos(this->x_y_.first * this->C_));
				this->res_.push_back({ this->x_y_.first, this->x_y_.second });
				for (const auto& point : this->res_) {
					default_can.plot(this->x_y_.first, this->x_y_.second);
				}
				std::cout << default_can;
				std::chrono::milliseconds timespan(500);
				std::this_thread::sleep_for(timespan);
			}
		}
		catch (...) {
			std::cerr << "Some data error" << std::endl;
		} break;

	case 3:
		try {
			for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
				this->x_y_.second = this->A_ * log(this->B_ * this->x_y_.first);
				this->res_.push_back({ this->x_y_.first, this->x_y_.second });
				for (const auto& point : this->res_) {
					default_can.plot(this->x_y_.first, this->x_y_.second);
				}
				main_menu(this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp);
				std::cout << default_can;
				std::chrono::milliseconds timespan(500);
				std::this_thread::sleep_for(timespan);
			}
		}
		catch (...) {
			std::cerr << "Some data error" << std::endl;
		} break;

	case 4:
		try{
			for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
				this->x_y_.second = this->A_ / ((sin(std::pow(this->x_y_.first, 2))) * this->B_);
				this->res_.push_back({ this->x_y_.first, this->x_y_.second });
				for (const auto& point : this->res_) {
					default_can.plot(this->x_y_.first, this->x_y_.second);
				}
				main_menu(this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp);
				std::cout << default_can;
				std::chrono::milliseconds timespan(500);
				std::this_thread::sleep_for(timespan);
			}
		}
		catch (...) {
			std::cerr << "Some data error" << std::endl;
		} break;

	case 5:
		try {
			for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
				this->x_y_.second = 4 * sin(this->x_y_.first / 2);
				this->res_.push_back({ this->x_y_.first, this->x_y_.second });
				for (const auto& point : this->res_) {
					default_can.plot(this->x_y_.first, this->x_y_.second);
				}
				main_menu(this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp);
				std::cout << default_can;
				std::chrono::milliseconds timespan(500);
				std::this_thread::sleep_for(timespan);
			}
		}
		catch (...) {
			std::cerr << "Some data error" << std::endl;
		} break;

	default:
		break;
	}

	
}