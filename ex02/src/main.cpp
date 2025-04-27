/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/27 11:17:19 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Fixed.hpp"

int main()
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) ); // std::cout << b << std::endl;
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) ); // std::cout << c << std::endl;
	Fixed const d( Fixed( 5.05f ) - Fixed( 2 ) ); // std::cout << d << std::endl;
	Fixed const e( Fixed( 5.05f ) + Fixed( 2 ) ); // std::cout << e << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;

	std::cout << a << std::endl;

	// std::cout << --a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a-- << std::endl;
	// std::cout << a << std::endl;




	std::cout << "a, b max :" << Fixed::max( a, b ) << std::endl;
	std::cout << "b, a max :" << Fixed::max( b, a ) << std::endl;
	std::cout << "a, b min :" << Fixed::min( a, b ) << std::endl;
	std::cout << "b, a min :" << Fixed::min( b, a ) << std::endl;
	return 0;
}
// 0
// 0.00390625
// 0.00390625
// 0.00390625

// 0.0078125

// 10.1016
// 10.1016
