#ifndef WARLOCK_HPP
#define WARLOCK_HPP

class	ATarget;

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"

class	Warlock
{
	private:
		const std::string	_name;
		std::string			_title;
		SpellBook*			_book;

		Warlock();
		Warlock( const Warlock &w );

		Warlock&	operator=( const Warlock &w );

	public:
		Warlock( std::string name, std::string title );
		~Warlock();

		const std::string	getName() const;
		const std::string	getTitle() const;
		void				setTitle( std::string title );
		void				introduce() const;

		void	learnSpell( ASpell *as );
		void	forgetSpell( std::string spell );
		void	launchSpell( std::string spell, ATarget &at );
};

#endif