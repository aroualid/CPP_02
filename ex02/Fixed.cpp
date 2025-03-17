#include "Fixed.hpp"
#include  <cmath>

Fixed::Fixed(): raw_value(0)
{
	//std::cout << "Default constructor called\n";
}

Fixed::~Fixed()
{
//	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed const &c)
{
//	std::cout << "Copy constructor called\n";
	*this = c;
}

Fixed &Fixed::operator=(Fixed const &c)
{
//	std::cout << "Copy assignment operator called\n";
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
//	std::cout << "Int constructor called\n";
	raw_value = int_raw << mantis;
}


Fixed::Fixed(const float float_raw)
{
//	std::cout << "Float constructor called\n";
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

Fixed Fixed::operator+(Fixed const &c)
{
	raw_value += c.getRawBits();
	
	return (*this);
}

Fixed Fixed::operator-(Fixed const &c)
{
	raw_value -= c.getRawBits();
	
	return (*this);
}

Fixed Fixed::operator/(Fixed const &c)
{
	if (c.getRawBits() == 0)
	{
		std::cout << "NO DIVISION BY 0 !!!!!(so crazy)\n";
		return (0);
	}
	return Fixed(this->toFloat() / c.toFloat());
}

Fixed Fixed::operator*(Fixed const &c)
{
    return Fixed(this->toFloat() * c.toFloat());
}

bool Fixed::operator>(Fixed const &c)
{
	if (raw_value > c.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<(Fixed const &c)
{
	if (raw_value < c.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator<=(Fixed const &c)
{
	if (raw_value <= c.getRawBits())
		return (true);
	else
		return (false);
}


bool Fixed::operator>=(Fixed const &c)
{
	if (raw_value >= c.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator!=(Fixed const &c)
{
	if (raw_value != c.getRawBits())
		return (true);
	else
		return (false);
}

bool Fixed::operator==(Fixed const &c)
{
	if (raw_value == c.getRawBits())
		return (true);
	else
		return (false);
}

Fixed Fixed::operator++(int)
{
	Fixed a(*this);
	raw_value++;
	return (a);
}

Fixed Fixed::operator--(int)
{
	Fixed a(*this);
	raw_value--;
	return (a);
}

Fixed Fixed::operator++(void)
{
	raw_value++;
	return (*this);
}


Fixed Fixed::operator--(void)
{
	raw_value--;
	return (*this);
}



Fixed &Fixed::min(Fixed &nb1, Fixed &nb2) {
    if (nb1.getRawBits() < nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

const Fixed &Fixed::min(const Fixed &nb1, const Fixed &nb2) {
    if (nb1.getRawBits() < nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

Fixed &Fixed::max(Fixed &nb1, Fixed &nb2) {
    if (nb1.getRawBits() > nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}

const Fixed &Fixed::max(const Fixed &nb1, const Fixed &nb2) {
    if (nb1.getRawBits() > nb2.getRawBits()) {
        return nb1;
    }
    return nb2;
}
