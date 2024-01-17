#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock( const Warlock &w)
{
	(void)w;
}

Warlock::Warlock( std::string name, std::string title )
	: _name(name), _title(title), _book( new SpellBook() )
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

void	Warlock::learnSpell( ASpell *as )
{
	this->_book->learnSpell(as);
}

void	Warlock::forgetSpell( std::string spell )
{
	this->_book->forgetSpell(spell);
}

void	Warlock::launchSpell( std::string spell, ATarget &at )
{
	ASpell*	as = this->_book->createSpell(spell);

	if (as)
	{
		as->launch(at);
		delete as;
	}
}