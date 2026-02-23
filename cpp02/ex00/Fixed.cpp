#include "Fixed.hpp"

const int Fixed::frac = 8;

Fixed::Fixed():num(0)
{
	std::cout<< "Default constructor called"<<std::endl;
}
Fixed::Fixed(int const num)
{
	std::cout<< "Int constructor called"<<std::endl;
	this->num = num << frac;
}
Fixed::Fixed(float const num)
{
	std::cout<< "Float constructor called"<<std::endl;
	this->num = roundf(num * (1 << frac));
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

int Fixed::toInt( void ) const{
	return this->num >> frac;
 }

float Fixed::toFloat( void ) const{
	return (float)this->num / (1 << frac);
}

 std::ostream& operator<<(std::ostream& os, const Fixed& src)
{
	os << src.toFloat();
	return os;
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
