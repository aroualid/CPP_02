#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <iterator>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const & c);
		Fixed & operator=(Fixed const & c);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits (int const raw);	
		Fixed(const int int_raw);
		Fixed(const float float_raw);	
		float toFloat(void) const;
		int toInt(void) const;	
	private:
		int raw_value;
		static const int mantis = 8;
};

std::ostream& operator<< (std::ostream& o, Fixed const& f);

#endif
 
