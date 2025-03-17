#include "Fixed.hpp"
#include  <cmath>

Fixed::Fixed(): raw_value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &c)
{
	std::cout << "Copy constructor called\n";
	*this = c;
}

Fixed & Fixed::operator=(Fixed const &c)
{
	std::cout << "Copy assignment operator called\n";
	raw_value = c.getRawBits();
	
	return (*this);
}

int Fixed::getRawBits(void) const
{
	return (raw_value);
}

void Fixed::setRawBits(int const raw)
{
	raw_value = raw;
}

Fixed::Fixed(const int int_raw)
{
	std::cout << "Int constructor called\n";
	raw_value = int_raw << mantis;
}

Fixed::Fixed(const float float_raw)
{
	std::cout << "Float constructor called\n";
	raw_value = roundf(float_raw * (1 << mantis));
}

float Fixed::toFloat(void) const
{
	return (raw_value / (float)(1 << mantis));
}

int Fixed::toInt(void) const
{
	return (raw_value >> mantis);
}

std::ostream& operator<< (std::ostream& o, Fixed const& f)
{
	o << f.toFloat();
	return o;
}
