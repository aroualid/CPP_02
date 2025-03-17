#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed{
	public:
		Fixed();
		Fixed(Fixed const & c);
		Fixed & operator=(Fixed const & c);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits (int const raw);	
	private:
		int raw_value;
		static const int mantis = 8;
};


#endif
