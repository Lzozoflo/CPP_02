/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/26 16:40:39 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fracBits = 8;

/*---------------constructor------Canonical-------destructor----------------*/



Fixed::Fixed( void )	:	_value( 0 )
{
	std::cout << BLUE << "Default Constructor is Called" << RESET << std::endl;

}


Fixed::Fixed( const Fixed &other )
{

	this->_value = other._value;
	std::cout << BLUE << "Copy Constructor is Called" << RESET << std::endl;

}


Fixed &Fixed::operator=( const Fixed &other )
{

	std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;
	if (this != &other)
		this->_value = other._value;

	return	*this;

}


Fixed::~Fixed( void )
{

	std::cout << YELLOW << "Destructor is Called" << RESET << std::endl;

}



/*---------------constructor------Canonical-------destructor----------------*/


int		Fixed::getRawBits( void )
{

	std::cout << "getRawBits is Called" << std::endl;

	return	(this->_value);

}


void	Fixed::setRawBits( int const raw )
{

	this->_value = raw;
	std::cout << "getRawBits is Called" << std::endl;

}

