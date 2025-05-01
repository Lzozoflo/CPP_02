/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/27 16:42:01 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

//Can be equal neg or pos
int	pos_point( Point const p1, Point const p2, Point const point)
{
	return (
				(point.getFixedX() - p1.getFixedX()) * (p2.getFixedY() - p1.getFixedY())
			-
				(point.getFixedY() - p1.getFixedY()) * (p2.getFixedX() - p1.getFixedX())
	);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	std::cout << point.getFixedX() << ", " << point.getFixedY();

	float d1 = pos_point( a, b, point ); //	AB
	float d2 = pos_point( b, c, point ); //	BC
	float d3 = pos_point( c, a, point ); //	CA


	int has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	int has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	if ((a == point) || (b == point) || (c == point) || (d1 == 0) || (d2 == 0) || (d3 == 0))
		return (1);
	return (has_neg && has_pos);
}

int main()
{
	Point a( 0, 0 );
	Point b( 0, 4 );
	Point c( 0, 5 );
	Point p( 0, 3 );


	if (bsp( a, b, c, p)){
		std::cout << " is out" << std::endl;
		return (1);}
	return (0);
}
