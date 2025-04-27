
#include "Point.hpp"


/*---------------constructor------Canonical-------destructor----------------*/

Point::Point( void )	:	_x( 0 ), _y(0)
{
	// std::cout << BLUE << "Default Constructor is Called" << RESET << std::endl;

}


Point::Point( const Point &other ) : _x( other._x ), _y(other._y)
{
	// std::cout << BLUE << "Copy Constructor is Called" << RESET << std::endl;
}


Point &Point::operator=( const Point &other )
{

	// std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;
	if (this != &other){
	// 	this->_x = other._x;
	// 	this->_y = other._y;
	}

	return	*this;

}


Point::~Point( void )
{

	// std::cout << YELLOW << "Destructor is Called" << RESET << std::endl;

}

/*---------------constructor------Canonical-------destructor----------------*/


/*---------------constructor-------------destructor----------------*/


Point::Point( const float &x, const float &y )	:	_x( x ), _y( y )
{
	// std::cout << BLUE << "2float const Constructor is Called" << RESET << std::endl;
}


/*---------------constructor-------------destructor----------------*/

/*----operator----*/


bool Point::operator==( const Point &other ) const {return (this->getFixedX() == other.getFixedX() && this->getFixedY() == other.getFixedY());}


/*----func----*/



float	Point::getFixedX( void ) const {return (this->_x.toFloat());}
float	Point::getFixedY( void ) const {return (this->_y.toFloat());}
