/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 14:27:31 by fcretin           #+#    #+#             */
/*   Updated: 2025/05/01 13:34:06 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POINT_HPP
#define POINT_HPP


#include <iostream>
#include "Fixed.hpp"


#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN  "\033[32m"
#define BLUE  "\033[34m"
#define YELLOW "\033[33m"


class Point
{
	private:
	// {
		const Fixed	_x;
		const Fixed	_y;


	// }
	public:
	// {

		Point( void );									//Canonical
		Point( const Point &b );						//Canonical
		Point &operator=( const Point &b );				//Canonical
		~Point( void );									//Canonical

		Point( const float &x, const float &y );

		bool operator==( const Point &other ) const ;
		float	getFixedX( void ) const;
		float	getFixedY( void ) const;

	// }
};


#endif
