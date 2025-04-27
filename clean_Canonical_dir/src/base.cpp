
#include "base.hpp"


/*---------------constructor------Canonical-------destructor----------------*/

Base::Base( void )	:	_value( 0 )
{
	std::cout << BLUE << "Default Constructor is Called" << RESET << std::endl;

}


Base::Base( const Base &other )
{

	this->_value = other._value;
	std::cout << BLUE << "Copy Constructor is Called" << RESET << std::endl;

}


Base &Base::operator=( const Base &other )
{

	std::cout << BLUE << "Operator '=' is Called" << RESET << std::endl;
	if (this != &other)
		this->_value = other._value;

	return	*this;

}


Base::~Base( void )
{

	std::cout << YELLOW << "Destructor is Called" << RESET << std::endl;

}

/*---------------constructor------Canonical-------destructor----------------*/
