#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock( const Warlock &w)
{
	(void)w;
}

Warlock::Warlock( std::string name, std::string title )
	: name(name), title(title)
{
	std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string	Warlock::getName() const
{
	return (this->name);
}

const std::string	Warlock::getTitle() const
{
	return (this->title);
}

void	Warlock::setTitle( std::string title )
{
	this->title = title;
}

void	Warlock::introduce() const
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void	Warlock::learnSpell( ASpell *as )
{
	Warlock::Iter	it = this->_inven.find(as->getName());

	if (it == this->_inven.end())
		this->_inven.insert(Warlock::Pair( as->getName(), as->clone()) );
}

void	Warlock::forgetSpell( std::string spell )
{
	Warlock::Iter	it = this->_inven.find(spell);

	if (it != this->_inven.end())
	{
		delete it->second;
		this->_inven.erase(it);
	}
}

void	Warlock::launchSpell( std::string spell, ATarget &at )
{
	Warlock::Iter	it = this->_inven.find(spell);

	if (it != this->_inven.end())
		at.getHitBySpell(*(it->second));
}