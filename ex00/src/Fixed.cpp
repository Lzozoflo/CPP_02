/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/28 12:37:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_FracBits = 8;

/*---------------constructor------Canonical-------destructor----------------*/



Fixed::Fixed( void )	:	_Value( 0 )
{
	std::cout << BLUE << "Default Constructor is Called" << RESET << std::endl;
}


Fixed::Fixed( const Fixed &other )
{

	this->_Value = other._Value;
	std::cout << BLUE << "Copy Constructor is Called" << RESET << std::endl;

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
