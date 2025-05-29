/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/28 12:57:41 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <climits>
#include <cfloat>

const int Fixed::_FracBits = 8;

/*---------------constructor------Canonical-------destructor----------------*/



Fixed::Fixed( void )	:	_Value( 0 )
{
	std::cout << BLUE << "Constructor Default is Called" << RESET << std::endl;
}


Fixed::Fixed( const Fixed &other )
{
	this->_Value = other._Value;
	std::cout << BLUE << "Constructor Copy is Called" << RESET << std::endl;
}


Fixed &Fixed::operator=( const Fixed &other )
{
	std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;
	if (this != &other)
		this->_Value = other._Value;
	return	*this;
}


Fixed::~Fixed( void )
{
	std::cout << YELLOW << "Destructor is Called" << RESET << std::endl;
}


/*---------------constructor------Canonical-------destructor----------------*/


/*---------------constructor-------------destructor----------------*/


Fixed::Fixed( int const value )
{
	std::cout << BLUE << "Constructor int is Called" << RESET << std::endl;

	if (value > (INT_MAX >> this->_FracBits) || value < (INT_MIN >> this->_FracBits)) {
		std::cout << RED << "Error: int value too high to be stored as fixed point." << RESET << std::endl;
		this->_Value = 0;
		return;
	}
	this->_Value = value << this->_FracBits;
}


Fixed::Fixed( float const value )
{
	std::cout << BLUE << "Constructor float is Called" << RESET << std::endl;

	if (value > (FLT_MAX / this->_FracBits) || value < (FLT_MIN / this->_FracBits))
	{
		std::cout << RED << "Error: float value too high to be stored as fixed point." << RESET << std::endl;
		this->_Value = 0;
		return;
	}
	this->_Value = roundf(value * (1 << this->_FracBits));
}


/*---------------constructor-------------destructor----------------*/

/*----fixed point----*/


float Fixed::toFloat( void ) const {return ((float)this->_Value / (1 << this->_FracBits));}
int Fixed::toInt( void ) const {return (this->_Value >> this->_FracBits);}


/*----func----*/


int		Fixed::getRawBits( void )
{

	std::cout << BLUE << "getRawBits is Called" << RESET  << std::endl;
	return	(this->_Value);

}


void	Fixed::setRawBits( int const raw )
{

	std::cout << BLUE << "getRawBits is Called" << RESET  << std::endl;
	this->_Value = raw;

}


/*----func----*/

std::ostream& operator<<( std::ostream &refo ,const Fixed &other )
{
	refo << other.toFloat();
	return refo;
}
