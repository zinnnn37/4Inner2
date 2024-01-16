#ifndef ASPELL_HPP
#define ASPELL_HPP

class	ATarget;

#include <iostream>
#include <string>
#include "ATarget.hpp"

class	ASpell
{
	private:
		std::string	_name;
		std::string	_effects;

	public:
		ASpell();
		ASpell( std::string name, std::string effects );
		ASpell( const ASpell& as );
		virtual ~ASpell();

		ASpell&	operator=( const ASpell& as );

		std::string	getName() const;
		std::string	getEffects() const;

		virtual	ASpell*	clone() const = 0;

		void	launch( const ATarget& at ) const;
};

#endif