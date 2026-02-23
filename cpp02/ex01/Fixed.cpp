#include "Fixed.hpp"


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
const int Fixed::fraction = 8;


int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->num;
}

void Fixed::setRawBits(int const raw)
{
	this->num = raw;
}
