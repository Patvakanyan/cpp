#include "Fixed.hpp"

const int Fixed::fraction = 8;

Fixed::Fixed():num(0)
{
	std::cout<< "Default constructor called"<<std::endl;
}

Fixed::~Fixed()
{
	std::cout<< "Destructor called"<<std::endl;
}

Fixed& Fixed::operator=(const Fixed &src)
{
	std::cout<<"Copy assignment operator called"<<std::endl;
	if(this == &src)
		return *this;
	this->num = src.getRawBits();
	return *this;
}

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

Fixed::Fixed(const Fixed &src)
{
	std::cout<< "Copy constructor called"<< std::endl;
	this->num = src.getRawBits();
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

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

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() < b.getRawBits() ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return a.getRawBits() > b.getRawBits() ? a : b;
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}

Fixed::Fixed(int const num)
{
	std::cout<< "Int constructor called"<<std::endl;
	this->num = num << fraction;
}

Fixed::Fixed(float const num)
{
	std::cout<< "Float constructor called"<<std::endl;
	this->num = roundf(num * (1 << fraction));
}

float Fixed::toFloat(void) const
{
	return (float)this->num / (1 << fraction);
}

int Fixed::toInt(void) const
{
	return this->num >> fraction;
}

std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
}
