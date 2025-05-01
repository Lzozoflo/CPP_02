/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/01 13:24:03 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	this->_Value = value << this->_FracBits;
	std::cout << BLUE << "Constructor int is Called" << RESET << std::endl;
}


Fixed::Fixed( float const value )
{
	this->_Value = roundf(value * (1 << this->_FracBits));
	std::cout << BLUE << "Constructor float is Called" << RESET << std::endl;
}


/*---------------constructor-------------destructor----------------*/


/*----func----*/


int		Fixed::getRawBits( void )
{
	std::cout << "getRawBits is Called" << std::endl;
	return	(this->_Value);
}


void	Fixed::setRawBits( int const raw )
{
	this->_Value = raw;
	std::cout << "getRawBits is Called" << std::endl;
}


float Fixed::toFloat( void ) const
{
	return ((float)this->_Value / (1 << this->_FracBits));
}


int Fixed::toInt( void ) const
{
	return (this->_Value >> this->_FracBits);
}


/*----func----*/

std::ostream& operator<<( std::ostream &refo ,const Fixed &other )
{
	refo << other.toFloat();
	return refo;
}
