#define M_PI (3.14159265358979323846)

#include <iostream>
#include <array>
#include <cmath>
namespace gsch{
    template <unsigned long TColumns = 100, unsigned long TRows = 50>
    struct Drawings {
        using Line = std::array<char, TColumns>;
        using Screen = std::array<Line, TRows>;
        struct Coord { unsigned long x, y; };

        static constexpr unsigned long Rows() { return TRows; }
        static constexpr unsigned long cols() { return TColumns; }

        Screen screen;
        Coord origin;

        Drawings(Coord origin = { TColumns / 2, TRows / 2 }) : origin(origin) {
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

    Line& operator[](unsigned long y) { return screen.at(screen.size() - (y + 1)); }
    Line const& operator[](unsigned long y) const { return screen.at(screen.size() - (y + 1)); }
    char& operator[](Coord coord) { return operator[](coord.y).at(coord.x); }
    char const& operator[](Coord coord) const { return operator[](coord.y).at(coord.x); }

        void axes() {
            bool ctr = false;
            for (auto& line : screen) {
                if (!ctr) {
                    line.at(origin.x) = '^';
                    ctr = true;
                }
                else {
                    line.at(origin.x) = '|';
                }
            }
            auto& yaxis = operator[](origin.y);
            for (auto& cell : yaxis) {
                cell = '-';
                yaxis.at(origin.x) = '+';
                yaxis.at((origin.x * 2) - 1) = '>';
            }
        }

        void plot(double X, double Y) {
            unsigned long xtick = (X * 1.0) + origin.x;
            unsigned long ytick = (Y / 1.0) + origin.y;
            if (xtick < TColumns && ytick < TRows) {
                operator[]({ xtick, ytick }) = '*';
            } else {
                return;
            }
        }
    };
} //gsch