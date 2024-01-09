#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock( const Warlock &w )
{
	(void)w;
}

Warlock&	Warlock::operator=( const Warlock &w )
{
	if (this != &w)
	{
		this->_name = w.getName();
		this->_title = w.getTitle();
	}
	return (*this);
}

Warlock::Warlock( std::string name, std::string title )
	: _name(name), _title(title)
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}

const std::string	Warlock::getName() const
{
	return (this->_name);
}

const std::string	Warlock::getTitle() const
{
	return (this->_title);
}

void	Warlock::setTitle( std::string title )
{
	this->_title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}
