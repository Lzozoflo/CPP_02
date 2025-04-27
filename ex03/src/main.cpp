/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcretin <fcretin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 11:06:45 by fcretin           #+#    #+#             */
/*   Updated: 2025/04/27 15:50:48 by fcretin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

// // Calcule de quel côté est un point p par rapport à la droite p1->p2
// float side(t_vec2 p1, t_vec2 p2, t_vec2 p) {
//     // Vecteur u = p1 -> p2
//     // Vecteur v = p1 -> p
//     // Produit vectoriel u x v
//     return (p.x - p1.x) * (p2.y - p1.y) - (p.y - p1.y) * (p2.x - p1.x);
// }

// // Fonction principale : est-ce que p est dans le triangle ABC ?
// int point_in_triangle_bsp(t_vec2 p, t_vec2 a, t_vec2 b, t_vec2 c) {
//     float d1, d2, d3;
//     int has_neg, has_pos;

//     // Calculer le signe pour chaque côté
//     d1 = side(a, b, p); // côté AB
//     d2 = side(b, c, p); // côté BC
//     d3 = side(c, a, p); // côté CA

//     // Est-ce que le point est du mauvais côté ?
//     has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//     has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

//     // Si les signes ne sont pas tous positifs ou tous négatifs => dehors
//     return !(has_neg && has_pos);
// }

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
	Point a( 0, 2 );
	Point b( 4, 0 );
	Point c( 4, 4 );
	Point p( 2, 3 );


	if (bsp( a, b, c, p)){
		std::cout << " is out" << std::endl;
		return (1);}
	return (0);
}
