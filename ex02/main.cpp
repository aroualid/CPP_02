#include "Fixed.hpp"
#include <iostream>

int main( void )
{
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(-50.2f);
    Fixed d(28);
    Fixed e(15.278f);
    Fixed f(0);
    Fixed g(2);
    Fixed zero(0);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "max between a :" << a << " and b :" << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << "min between a :" << a << " and b :" << b << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    if (c < d)
        std::cout << c << " is < to " << d << std::endl;
    if (d > e)
        std::cout << d << " > " << e << std::endl;
    if (f >= zero)
        std::cout << f << " >= " << zero << std::endl;
    if (f <= zero)
        std::cout << f << " <= " << zero << std::endl;
    if (f == zero)
        std::cout << f << " == " << zero << std::endl;
    if (d != zero)
        std::cout << d << " != " << zero << std::endl;
    std::cout << d << " + " << e << " = " << d + e << std::endl;
    std::cout << d << " - " << e << " = " << d - e << std::endl;
    std::cout << d << " * " << g << " = " << d * g << std::endl;
    std::cout << d << " / " << g << " = " << d / g << std::endl;
    std::cout << d << " / " << zero << " = " << d / zero << std::endl;
    return 0;
}
