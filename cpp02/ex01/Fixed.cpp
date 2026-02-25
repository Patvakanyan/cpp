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
