#include "Fixed.hpp"

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
	std::cout << "getRawBits member function called\n";
	return (raw_value);
}

void Fixed::setRawBits(int const raw)
{
	raw_value = raw;
}
