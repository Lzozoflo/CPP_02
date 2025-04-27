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

		int					_value;
		static const int	_fracBits;

	// }
	public:
	// {

		Fixed( void );									//Canonical
		Fixed( const Fixed &other );					//Canonical
		Fixed &operator=( const Fixed &other );			//Canonical
		~Fixed( void );									//Canonical

		Fixed( int const value );
		Fixed( float const value );


		/*----comparison operator---- */
		bool operator>( const Fixed &other );
		bool operator<( const Fixed &other );
		bool operator>=( const Fixed &other );
		bool operator<=( const Fixed &other );
		bool operator==( const Fixed &other );
		bool operator!=( const Fixed &other );


		/*----arithmetic operators----*/
		Fixed operator+( const Fixed &other );
		Fixed operator-( const Fixed &other );
		Fixed operator*( const Fixed &other );
		Fixed operator/( const Fixed &other );


		/*----increment and decrement operators----*/
		Fixed &operator++( ); // pre
		Fixed &operator--( ); // pre
		Fixed operator++( int ); // post
		Fixed operator--( int ); // post

		/*----min max----*/
		static float max( Fixed &Ref1, Fixed &Ref2 );
		static float min( Fixed &Ref1, Fixed &Ref2 );
		/*----const min max----*/
		static float max( const Fixed &Ref1, const Fixed &Ref2 );
		static float min( const Fixed &Ref1, const Fixed &Ref2 );

		/*----Func----*/
		int	getRawBits( void );
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;

	// }
};


std::ostream& operator<<( std::ostream &refo ,const Fixed &other );

#endif

// Ajoutez à votre classe des fonctions membres publiques afin de surcharger les opérateurs suivants :
// • Les 6 opérateur de comparaison : >, <, >=, <=, == et !=.
// • Les 4 opérateurs de arithmétiques : +, -, *, et /.
// • Les 4 opérateurs d’incrémentation et de décrémentation (pré-incrémentation et
// post-incrémentation, pré-décrémentation et post-décrémentation) qui diminueront
// la valeur du nombre à virgule fixe d’unité ϵ tel que 1 + ϵ > 1.
