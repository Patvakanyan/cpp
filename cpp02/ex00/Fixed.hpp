#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>
#include <iostream>

class Fixed
{
	public:
		// Creates a fixed-point value initialized to zero.
		Fixed();
		// Creates a fixed-point value from an integer.
		Fixed(int const num);
		// Creates a fixed-point value from a floating-point number.
		Fixed(float const num);
		// Destroys the fixed-point instance.
		~Fixed();
		// Creates a fixed-point value by copying another instance.
		Fixed(const Fixed &src);
		// Assigns the value from another fixed-point instance.
		Fixed& operator=(const Fixed& src);
	public:
		// Converts the stored fixed-point value to float.
		float toFloat( void ) const;
		// Converts the stored fixed-point value to int.
		int toInt( void ) const;
		// Returns the raw fixed-point bits.
		int getRawBits( void ) const;
		// Replaces the raw fixed-point bits.
		void setRawBits( int const raw );
	private:
		int num;
		static const int frac;
};

#endif
