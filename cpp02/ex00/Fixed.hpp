#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>
#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int const num);
		Fixed(float const num);
		~Fixed();
		Fixed(const Fixed &src);
		Fixed& operator=(const Fixed& src);
	public:
		float toFloat( void ) const;
		int toInt( void ) const;
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int num;
		static const int frac;
};

#endif
