#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed& src);
	public:
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int num;
		static const int fraction;
};

#endif
