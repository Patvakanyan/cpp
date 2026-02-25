#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>
#include <iostream>

class Fixed
{
	public:
		// Creates a fixed-point value initialized to zero.
		Fixed();
		// Destroys the fixed-point instance.
		~Fixed();
		// Creates a fixed-point value by copying another instance.
		Fixed(const Fixed &src);
		// Assigns the value from another fixed-point instance.
		Fixed& operator=(const Fixed& src);
		// Creates a fixed-point value from an integer.
		Fixed(int const num);
		// Creates a fixed-point value from a floating-point number.
		Fixed(float const num);
	public:
		// Returns true if this value is greater than src.
		bool operator>(const Fixed& src) const;
		// Returns true if this value is smaller than src.
		bool operator<(const Fixed& src) const;
		// Returns true if this value is greater than or equal to src.
		bool operator>=(const Fixed& src) const;
		// Returns true if this value is smaller than or equal to src.
		bool operator<=(const Fixed& src) const;
		// Returns true if values are different.
		bool operator!=(const Fixed& src) const;
		// Returns true if values are equal.
		bool operator==(const Fixed& src) const;

		// Multiplies two fixed-point values.
		Fixed operator*(const Fixed& src) const;
		// Subtracts src from this value.
		Fixed operator-(const Fixed& src) const;
		// Adds two fixed-point values.
		Fixed operator+(const Fixed& src) const;
		// Divides this value by src.
		Fixed operator/(const Fixed& src) const;

		// Prefix increment.
		Fixed &operator++();
		// Postfix increment.
		Fixed operator++(int);
		// Postfix decrement.
		Fixed operator--(int);
		// Prefix decrement.
		Fixed &operator--();
	public:
		// Returns the larger non-const reference.
		static Fixed& max(Fixed& a, Fixed& b);
		// Returns the larger const reference.
		static const Fixed& max(const Fixed& a, const Fixed& b);
		// Returns the smaller non-const reference.
		static Fixed& min(Fixed& a, Fixed& b);
		// Returns the smaller const reference.
		static const Fixed& min(const Fixed& a, const Fixed& b);
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
		static const int fraction;
};

std::ostream& operator<<(std::ostream& os, const Fixed& src);


#endif
