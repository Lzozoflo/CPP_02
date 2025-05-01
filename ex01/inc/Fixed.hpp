/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:27:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/26 14:36:18 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP


#include <iostream>
#include <cmath>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define BLUE	"\033[34m"
#define YELLOW	"\033[33m"


class Fixed
{
	private:
	// {

		int					_Value;
		static const int	_FracBits;

	// }
	public:
	// {

		Fixed( void );									//Canonical
		Fixed( const Fixed &other );					//Canonical
		Fixed &operator=( const Fixed &other );			//Canonical
		~Fixed( void );									//Canonical

		Fixed( int const value );
		Fixed( float const value );


		int	getRawBits( void );
		void setRawBits( int const raw );

		float toFloat( void ) const;
		int toInt( void ) const;

	// }
};


std::ostream& operator<<( std::ostream &refo ,const Fixed &other );

#endif
