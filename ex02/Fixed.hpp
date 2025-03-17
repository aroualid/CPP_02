#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iterator>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const & c);
		Fixed &operator=(Fixed const & c);
		Fixed operator+(Fixed const & c);
		Fixed operator-(Fixed const & c);
		Fixed operator/(Fixed const & c);
		Fixed operator*(Fixed const & c);
		Fixed operator++(int);
		Fixed operator--(int);
		Fixed operator++(void);
		Fixed operator--(void);
		bool operator>(Fixed const & c);
		bool operator<(Fixed const & c);
		bool operator<=(Fixed const & c);
		bool operator>=(Fixed const & c);
		bool operator!=(Fixed const & c);
		bool operator==(Fixed const & c);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits (int const raw);	
		Fixed(const int int_raw);
		Fixed(const float float_raw);	
		float toFloat(void) const;
		int toInt(void) const;	
	    static Fixed &min(Fixed &nb1, Fixed &nb2);
		static const Fixed &min(const Fixed &nb1, const Fixed &nb2);
		static Fixed &max(Fixed &nb1, Fixed &nb2);
		static const Fixed &max(const Fixed &nb1, const Fixed &nb2);
	private:
		int raw_value;
		static const int mantis = 8;
};

std::ostream& operator<< (std::ostream& o, Fixed const& f);

#endif
 
