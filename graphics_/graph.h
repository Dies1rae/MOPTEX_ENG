#define M_PI (3.14159265358979323846)

#include <iostream>
#include <array>
#include <cmath>

template <size_t Columns = 100, size_t Rows = 50>
struct Drawings {
    using Line = std::array<char, Columns>;
    using Screen = std::array<Line, Rows>;
    struct Coord { size_t x, y; };

    static constexpr size_t rows() { return Rows; }
    static constexpr size_t cols() { return Columns; }

    Screen screen;
    Coord origin;

    Drawings(Coord origin = { Columns / 2, Rows / 2 }) : origin(origin) {
        Line empty;
        std::fill(empty.begin(), empty.end(), ' ');
        std::fill(screen.begin(), screen.end(), empty);
    }

    friend std::ostream& operator<<(std::ostream& os, Drawings const& c) {
        for (auto& line : c.screen) {
            os.write(line.data(), line.size()) << "\n";
        }
        return os;
    }

    Line& operator[](size_t y) { return screen.at(screen.size() - (y + 1)); }
    Line const& operator[](size_t y) const { return screen.at(screen.size() - (y + 1)); }
    char& operator[](Coord coord) { return operator[](coord.y).at(coord.x); }
    char const& operator[](Coord coord) const { return operator[](coord.y).at(coord.x); }

    void axes() {
        for (auto& line : screen)
            line.at(origin.x) = '|';

        auto& y_axis = operator[](origin.y);

        for (auto& cell : y_axis)
            cell = '-';

        y_axis.at(origin.x) = '+';
    }

    void plot( double X, double Y) {
        size_t x_tick = (X * 1.0) + origin.x;
        size_t y_tick = (Y / 1.0) + origin.y;
        if (x_tick < Columns && y_tick < Rows){
            operator[]({ x_tick, y_tick }) = '*';
        }
    }

};