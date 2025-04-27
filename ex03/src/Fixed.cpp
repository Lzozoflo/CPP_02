/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/27 13:37:23 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

/*---------------constructor------Canonical-------destructor----------------*/


Fixed::Fixed( void )	:	_value( 0 )
{
	// std::cout << BLUE << "Default Constructor is Called" << RESET << std::endl;
}


Fixed::Fixed( const Fixed &other )
{
	this->_value = other._value;
	// std::cout << BLUE << "Copy Constructor is Called" << RESET << std::endl;
}


Fixed &Fixed::operator=( const Fixed &other )
{
	// std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;

	if (this != &other)
		this->_value = other._value;

	return	*this;
}


Fixed::~Fixed( void )
{
	// std::cout << YELLOW << "Destructor is Called" << RESET << std::endl;
}


/*---------------constructor------Canonical-------destructor----------------*/



/*---------------constructor-------------destructor----------------*/

Fixed::Fixed( int const value )
{
	this->_value = value << _fracBits;
	// std::cout << BLUE << "Constructor int is Called" << RESET << std::endl;
}

Fixed::Fixed( float const value )
{
	this->_value = roundf(value * (1 << _fracBits));
	// std::cout << BLUE << "Constructor float is Called" << RESET << std::endl;
}


/*---------------constructor-------------destructor----------------*/



/*----fixed point----*/

float Fixed::toFloat( void ) const {return ((float)_value / (1 << _fracBits));}
int Fixed::toInt( void ) const {return (_value >> _fracBits);}

int		Fixed::getRawBits( void )
{
	// std::cout << "getRawBits is Called" << std::endl;
	return	(this->_value);
}

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "getRawBits is Called" << std::endl;
	this->_value = raw;
}

std::ostream& operator<<( std::ostream &refo ,const Fixed &other )
{
	refo << other.toFloat();
	return refo;
}

/*----comparison operator---- */

bool Fixed::operator>( const Fixed &other ){return (this->_value > other._value);}
bool Fixed::operator<( const Fixed &other ){return (this->_value < other._value);}
bool Fixed::operator>=( const Fixed &other ){return (this->_value >= other._value);}
bool Fixed::operator<=( const Fixed &other ){return (this->_value <= other._value);}
bool Fixed::operator==( const Fixed &other ){return (this->_value == other._value);}
bool Fixed::operator!=( const Fixed &other ){return (this->_value != other._value);}


/*----arithmetic operators----*/

Fixed Fixed::operator+( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits(this->_value + other._value);
	return (Res);
}

Fixed Fixed::operator-( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits(this->_value - other._value);
	return (Res);
}

Fixed Fixed::operator*( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits((this->_value * other._value) >> _fracBits);
	return (Res);
}

Fixed Fixed::operator/( const Fixed &other )
{
	if (other._value == 0)
	{
		std::cerr << RED << "Error: Division by zero! Set at default." << RESET << std::endl;
		return Fixed(0);
	}
	Fixed Res;
	Res.setRawBits((this->_value <<_fracBits) / other._value);
	return (Res);
}


/*----increment and decrement operators----*/

Fixed &Fixed::operator++( )
{
	// std::cout << BLUE << "pre + is Called" << RESET << std::endl;
	this->_value++;
	return (*this);
}// pre

Fixed &Fixed::operator--( )
{
	// std::cout << BLUE << "pre - is Called" << RESET << std::endl;
	this->_value--;
	return (*this);
}// pre

Fixed Fixed::operator++( int )
{
	// std::cout << BLUE << "post + is Called" << RESET << std::endl;
	Fixed tmp = *this;
	this->_value++;
	return (tmp);
}// post

Fixed Fixed::operator--( int )
{
	// std::cout << BLUE << "post - is Called" << RESET << std::endl;
	Fixed tmp = *this;
	this->_value--;
	return (tmp);
}// post


/*----min max----*/

float Fixed::max( Fixed &Ref1, Fixed &Ref2 )
{
	if (Ref1.toFloat() > Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}

float Fixed::min( Fixed &Ref1, Fixed &Ref2 )
{
	if (Ref1.toFloat() < Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}

/*----const min max----*/

float Fixed::max( const Fixed &Ref1, const Fixed &Ref2 )
{
	if (Ref1.toFloat() > Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}

float Fixed::min( const Fixed &Ref1, const Fixed &Ref2 )
{
	if (Ref1.toFloat() < Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}
