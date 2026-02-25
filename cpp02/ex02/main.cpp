#include <iostream>
#include "Fixed.hpp"

int main()
{
    std::cout << "===== COMPARISON TESTS =====" << std::endl;
    Fixed a(5.5f);
    Fixed b(2.25f);
    Fixed c(5.5f);

    std::cout << "a > b  : " << (a > b) << std::endl;
    std::cout << "a < b  : " << (a < b) << std::endl;
    std::cout << "a >= c : " << (a >= c) << std::endl;
    std::cout << "a <= c : " << (a <= c) << std::endl;
    std::cout << "a == c : " << (a == c) << std::endl;
    std::cout << "a != b : " << (a != b) << std::endl;


    std::cout << "\n===== ARITHMETIC TESTS =====" << std::endl;
    Fixed sum = a + b;
    Fixed sub = a - b;
    Fixed mul = a * b;
    Fixed div = a / b;

    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << sub << std::endl;
    std::cout << "a * b = " << mul << std::endl;
    std::cout << "a / b = " << div << std::endl;


    std::cout << "\n===== INCREMENT / DECREMENT TESTS =====" << std::endl;
    Fixed x(1);

    std::cout << "x          : " << x << std::endl;
    std::cout << "++x        : " << ++x << std::endl;  // pre-increment
    std::cout << "x          : " << x << std::endl;

    std::cout << "x++        : " << x++ << std::endl;  // post-increment
    std::cout << "x          : " << x << std::endl;

    std::cout << "--x        : " << --x << std::endl;  // pre-decrement
    std::cout << "x          : " << x << std::endl;

    std::cout << "x--        : " << x-- << std::endl;  // post-decrement
    std::cout << "x          : " << x << std::endl;


    std::cout << "\n===== MIN / MAX TESTS =====" << std::endl;
    Fixed d(10.1f);
    Fixed e(42.42f);

    std::cout << "min(d, e) = " << Fixed::min(d, e) << std::endl;
    std::cout << "max(d, e) = " << Fixed::max(d, e) << std::endl;

    const Fixed f(3.14f);
    const Fixed g(6.28f);

    std::cout << "min(f, g) = " << Fixed::min(f, g) << std::endl;
    std::cout << "max(f, g) = " << Fixed::max(f, g) << std::endl;

    return 0;
}
