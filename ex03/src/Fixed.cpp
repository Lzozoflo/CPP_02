/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:37:57 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/29 15:51:25 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"
#include <climits>
#include <cfloat>


const int		Fixed::_FracBits		=	8;

const int		Fixed::_ValueIntMax		=	INT_MAX >> 8;
const int		Fixed::_ValueIntMin		=	INT_MIN >> 8;



/*---------------constructor------Canonical-------destructor----------------*/


Fixed::Fixed( void )	:	_Value( 0 )
{
	// std::cout << BLUE << "Constructor Default is Called" << RESET << std::endl;
}


Fixed::Fixed( const Fixed &other )
{
	// std::cout << BLUE << "Constructor Copy is Called" << RESET << std::endl;
	this->_Value = other._Value;
}


Fixed &Fixed::operator=( const Fixed &other )
{
	// std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;
	if (this != &other)
		this->_Value = other._Value;
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
	// std::cout << BLUE << "Constructor int is Called" << RESET << std::endl;

	if (value > this->_ValueIntMax || value < this->_ValueIntMin) {
		std::cout << RED << "Error: int value too high to be stored as fixed point." << RESET << std::endl;
		this->_Value = 0;
		return;
	}
	this->_Value = value << this->_FracBits;
}


Fixed::Fixed( float const value )
{
	// std::cout << BLUE << "Constructor float is Called" << RESET << std::endl;

	if (value > this->_ValueIntMax || value < this->_ValueIntMin)
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

	// std::cout << BLUE << "getRawBits is Called" << RESET  << std::endl;
	return	(this->_Value);

}


void	Fixed::setRawBits( int const raw )
{

	// std::cout << BLUE << "getRawBits is Called" << RESET  << std::endl;
	this->_Value = raw;

}


/*----func----*/


/*----comparison operator---- */


bool Fixed::operator>( const Fixed &other ){return (this->_Value > other._Value);}
bool Fixed::operator<( const Fixed &other ){return (this->_Value < other._Value);}
bool Fixed::operator>=( const Fixed &other ){return (this->_Value >= other._Value);}
bool Fixed::operator<=( const Fixed &other ){return (this->_Value <= other._Value);}
bool Fixed::operator==( const Fixed &other ){return (this->_Value == other._Value);}
bool Fixed::operator!=( const Fixed &other ){return (this->_Value != other._Value);}

bool Fixed::operator>( const Fixed &other )const {return (this->_Value > other._Value);}
bool Fixed::operator<( const Fixed &other )const {return (this->_Value < other._Value);}

/*----comparison operator---- */


/*----arithmetic operators----*/


Fixed Fixed::operator+( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits(this->_Value + other._Value);
	return (Res);
}

Fixed Fixed::operator-( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits(this->_Value - other._Value);
	return (Res);
}

Fixed Fixed::operator*( const Fixed &other )
{
	Fixed Res;
	Res.setRawBits((this->_Value * other._Value) >> _FracBits);
	return (Res);
}

Fixed Fixed::operator/( const Fixed &other )
{
	if (other._Value == 0)
	{
		std::cout << RED << "Error: Division by zero! Set at default." << RESET << std::endl;
		return Fixed(0);
	}

	Fixed Res;
	Res.setRawBits((this->_Value <<_FracBits) / other._Value);
	return (Res);
}


/*----arithmetic operators----*/


/*----increment and decrement operators----*/


Fixed &Fixed::operator++( )
{
	// std::cout << BLUE << "pre + is Called" << RESET << std::endl;
	this->_Value++;
	return (*this);
}// pre

Fixed &Fixed::operator--( )
{
	// std::cout << BLUE << "pre - is Called" << RESET << std::endl;
	this->_Value--;
	return (*this);
}// pre

Fixed Fixed::operator++( int )
{
	// std::cout << BLUE << "post + is Called" << RESET << std::endl;
	Fixed tmp = *this;
	this->_Value++;
	return (tmp);
}// post

Fixed Fixed::operator--( int )
{
	// std::cout << BLUE << "post - is Called" << RESET << std::endl;
	Fixed tmp = *this;
	this->_Value--;
	return (tmp);
}// post


/*----increment and decrement operators----*/


/*----min max----*/


float Fixed::max( Fixed &Ref1, Fixed &Ref2 )
{
	if (Ref1 > Ref2)
		return (Ref1.toFloat());
	return (Ref2.toFloat());
	// if (Ref1.toFloat() > Ref2.toFloat())
	// 	return (Ref1.toFloat());
	// return (Ref2.toFloat());
}

float Fixed::min( Fixed &Ref1, Fixed &Ref2 )
{
	if (Ref1 < Ref2)
		return (Ref1.toFloat());
	return (Ref2.toFloat());
	// if (Ref1.toFloat() < Ref2.toFloat())
	// 	return (Ref1.toFloat());
	// return (Ref2.toFloat());
}


/*----min max----*/


/*----const min max----*/


float Fixed::max( const Fixed &Ref1, const Fixed &Ref2 )
{
	// if (Ref1 > Ref2)//bonus
	// 	return (Ref1.toFloat());
	// return (Ref2.toFloat());
	if (Ref1.toFloat() > Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}

float Fixed::min( const Fixed &Ref1, const Fixed &Ref2 )
{
	// if (Ref1 < Ref2)//bonus
	// 	return (Ref1.toFloat());
	// return (Ref2.toFloat());
	if (Ref1.toFloat() < Ref2.toFloat())
		return (Ref1.toFloat());
	return (Ref2.toFloat());
}


/*----const min max----*/


std::ostream& operator<<( std::ostream &refo ,const Fixed &other )
{
	refo << other.toFloat();
	return refo;
}
