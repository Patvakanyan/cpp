#include "Fixed.hpp"

// Static member initialization
const int Fixed::fraction = 8;

// Canonical constructors / destructor
Fixed::Fixed():num(0)
{
}

Fixed::~Fixed()
{
}

// Copy assignment
Fixed& Fixed::operator=(const Fixed &src)
{
	if(this == &src)
		return *this;
	this->num = src.getRawBits();
	return *this;
}

// Comparison operators
bool Fixed::operator>(const Fixed& src) const
{
	return this->num > src.getRawBits();
}

bool Fixed::operator<(const Fixed& src) const
{
	return this->num < src.getRawBits();
}

bool Fixed::operator>=(const Fixed& src) const
{
	return this->num >= src.getRawBits();
}

bool Fixed::operator<=(const Fixed& src) const
{
	return this->num <= src.getRawBits();
}

bool Fixed::operator==(const Fixed& src) const
{
	return this->num == src.getRawBits();
}

bool Fixed::operator!=(const Fixed& src) const
{
	return this->num != src.getRawBits();
}

// Arithmetic operators
Fixed Fixed::operator*(const Fixed& src) const
{
	Fixed ret;

	ret.setRawBits(((long long)this->getRawBits() * src.getRawBits()) >> fraction);
	return ret;
}

Fixed Fixed::operator+(const Fixed& src) const
{
	Fixed ret;

	ret.setRawBits(this->getRawBits() + src.getRawBits());
	return ret;
}

Fixed Fixed::operator-(const Fixed& src) const
{
	Fixed ret;

	ret.setRawBits(this->getRawBits() - src.getRawBits());
	return ret;
}

Fixed Fixed::operator/(const Fixed& src) const
{
	Fixed ret;

	ret.setRawBits(((long long)this->getRawBits()<<fraction) / src.getRawBits());
	return ret;
}

// Copy constructor
Fixed::Fixed(const Fixed &src)
{
	this->num = src.getRawBits();
}

// Raw bits accessors
int Fixed::getRawBits(void) const
{
	return this->num;
}

// Decrement operators
Fixed &Fixed::operator--()
{
	--num;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;

	--num;
	return tmp;
}

// Increment operators
Fixed &Fixed::operator++()
{
	++num;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;

	operator++();
	return tmp;
}

// Min helpers
Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

// Max helpers
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

// Raw bits mutator
void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

// Value constructors
Fixed::Fixed(int const num)
{
	this->num = num << fraction;
}

Fixed::Fixed(float const num)
{
	this->num = roundf(num * (1 << fraction));
}

// Conversions
float Fixed::toFloat(void) const
{
	return (float)this->num / (1 << fraction);
}

int Fixed::toInt(void) const
{
	return this->num >> fraction;
}

// Stream output operator
std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}
