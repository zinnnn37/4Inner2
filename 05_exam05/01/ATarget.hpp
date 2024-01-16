#ifndef ATARGET_HPP
#define ATARGET_HPP

class	ASpell;

#include <iostream>
#include <string>
#include "ASpell.hpp"

class	ATarget
{
	private:
		std::string	_type;
	
	public:
		ATarget();
		ATarget( std::string type );
		ATarget( const ATarget& at );
		~ATarget();

		ATarget&	operator=( const ATarget& at );

		const std::string&	getType() const;

		virtual ATarget*	clone() const = 0;

		void	getHitBySpell( const ASpell& as ) const;
};

#endif