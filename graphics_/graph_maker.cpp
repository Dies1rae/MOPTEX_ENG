#include "graph_maker.h"

#include "ascii_menu.h"

#include <future>
#include <thread>
#include <conio.h>
#include <mutex>
#include <atomic>

using namespace std::literals;

int menu_switcher() {
	int menu = _getch();
	return menu;
}

double graph_maker::get_percent() {
	this->percent_ = ((this->res_.size() - 1)/ ((this->to_ - this->from_) / this->step_)) * 100;
	return this->percent_;
}

void graph_maker::async_menu() {
	auto future = std::async(menu_switcher);
	if (future.wait_for(menu_timeout) == std::future_status::ready) {
		this->menu_switcher_ = future.get();
	}
}

void graph_maker::set_parametrs() {
	
	std::cout << "Please set parametrs for field A B C and FROM TO STEP"sv << std::endl;
	std::cin >> this->A_ >> this->B_ >> this->C_ >> this->from_ >> this->to_ >> this->step_;
}

void graph_maker::main_menu_loop() {
	if (this->start_) {
		default_can_.clear();
		default_can_.axes();
		this->percent_ = 0;
		main_menu(this->get_percent(), 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, "Choosen formula:", this->core_formulas_);
		std::cout << default_can_;

		this->set_parametrs();

		std::cout << "Choose formula: "sv << std::endl;
		for (size_t ptr = 0; ptr < this->core_formulas_.size(); ptr++) {
			std::cout << ptr + 1 << ": " << this->core_formulas_[ptr] << std::endl;
		}
		std::cin >> this->formula_num_;
		std::string formula_tmp = "Choosen formula: " + this->core_formulas_[this->formula_num_ - 1];
		main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
		std::cout << default_can_;

		switch (this->formula_num_) {
		case 1:
			try {
				for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
					this->x_y_.second = (this->A_ * std::pow(this->x_y_.first, 2)) + (this->B_ * this->x_y_.first) + this->C_;
					this->res_.push_back({ this->x_y_.first, this->x_y_.second });
					for (const auto& point : this->res_) {
						default_can_.plot(this->x_y_.first, this->x_y_.second);
					}
					main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
					std::cout << default_can_;
					std::chrono::milliseconds timespan(500);
					std::this_thread::sleep_for(timespan);
				}
			}
			catch (...) {
				std::cerr << "Some data error"sv << std::endl;
			} break;
		case 2:
			try {
				for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
					this->x_y_.second = (this->A_ * sin(this->x_y_.first)) + (this->B_ * cos(this->x_y_.first * this->C_));
					this->res_.push_back({ this->x_y_.first, this->x_y_.second });
					for (const auto& point : this->res_) {
						default_can_.plot(this->x_y_.first, this->x_y_.second);
					}
					main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
					std::cout << default_can_;
					std::chrono::milliseconds timespan(500);
					std::this_thread::sleep_for(timespan);
				}
			}
			catch (...) {
				std::cerr << "Some data error"sv << std::endl;
			} break;
		case 3:
			try {
				for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
					this->x_y_.second = this->A_ * log(this->B_ * this->x_y_.first);
					this->res_.push_back({ this->x_y_.first, this->x_y_.second });
					for (const auto& point : this->res_) {
						default_can_.plot(this->x_y_.first, this->x_y_.second);
					}
					main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
					std::cout << default_can_;
					std::chrono::milliseconds timespan(500);
					std::this_thread::sleep_for(timespan);
				}
			}
			catch (...) {
				std::cerr << "Some data error"sv << std::endl;
			} break;
		case 4:
			try {
				for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
					this->x_y_.second = this->A_ / ((sin(std::pow(this->x_y_.first, 2))) * this->B_);
					this->res_.push_back({ this->x_y_.first, this->x_y_.second });
					for (const auto& point : this->res_) {
						default_can_.plot(this->x_y_.first, this->x_y_.second);
					}
					main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
					std::cout << default_can_;
					std::chrono::milliseconds timespan(500);
					std::this_thread::sleep_for(timespan);
				}
			}
			catch (...) {
				std::cerr << "Some data error"sv << std::endl;
			} break;
		case 5:
			try {
				for (this->x_y_.first = this->from_; this->x_y_.first <= this->to_; this->x_y_.first += this->step_) {
					this->x_y_.second = 4 * sin(this->x_y_.first / 2);
					this->res_.push_back({ this->x_y_.first, this->x_y_.second });
					for (const auto& point : this->res_) {
						default_can_.plot(this->x_y_.first, this->x_y_.second);
					}
					main_menu(this->get_percent(), this->A_, this->B_, this->C_, this->from_, this->to_, this->step_, formula_tmp, this->core_formulas_);
					std::cout << default_can_;
					std::chrono::milliseconds timespan(500);
					std::this_thread::sleep_for(timespan);
				}
			}
			catch (...) {
				std::cerr << "Some data error"sv << std::endl;
			} break;
		default:
			break;
		}
	}
}

void graph_maker::run_loop() {
	
	default_can_.axes();
	
	while(!this->quit_){

		main_menu(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, "Choosen formula:", this->core_formulas_);
		std::cout << default_can_;

		std::cout << "Choose menu option: "sv << std::endl;
		this->menu_switcher_ = menu_switcher();
		switch (this->menu_switcher_) {
			//start
			case 49:
				this->start_ = true;
				break;
			case 115:
				this->start_ = true;
				break;
			//pause
			case 50:
				this->start_ = false;
				this->pause_ = true;
				break;
			case 112:
				this->start_ = false;
				this->pause_ = true;
				break;
			//brake
			case 51:
				this->start_ = false;
				this->brake_ = true;
				break;
			case 98:
				this->start_ = false;
				this->brake_ = true;
				break;
			//quit
			case 53:
				this->quit_ = true;
				this->start_ = false;
				this->brake_ = false;
				break;
			case 113:
				this->quit_ = true;
				this->start_ = false;
				this->brake_ = false;
				break;
			//info
			case 52:
				Info_menu(this->res_);
				break;
			case 105:
				Info_menu(this->res_);
				break;
			default:
				break;
		}

		this->main_menu_loop();
		this->start_ = false;
		system("PAUSE");
	}
}