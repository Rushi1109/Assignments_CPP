
#include "./include/Complex.h"

int main()
{
    Complex c1{ 6.9 };
    Complex c2{ 3.0, 6.0 };

    std::cout << c1 + c2 << '\n';
    std::cout << c2 + 2.5 << '\n';
    std::cout << 2.0 * c1 << '\n';
    c1 += c2;
    std::cout << c1 << '\n';
}

