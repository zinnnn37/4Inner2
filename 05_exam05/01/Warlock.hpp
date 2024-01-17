#ifndef WARLOCK_HPP
#define WARLOCK_HPP

class	ATarget;

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "ASpell.hpp"
#include "ATarget.hpp"

class	Warlock
{
	public:
		typedef	std::map< std::string, ASpell * >	Map;
		typedef	std::pair< std::string, ASpell * >	Pair;
		typedef	Map::iterator						Iter;

		Warlock( std::string name, std::string title );
		~Warlock();

		const std::string	getName() const;
		const std::string	getTitle() const;
		void				setTitle( std::string title );
		void				introduce() const;

		void	learnSpell( ASpell *as );
		void	forgetSpell( std::string spell );
		void	launchSpell( std::string spell, ATarget &at );

	private:
		const std::string	_name;
		std::string			_title;
		Map					_inven;

		Warlock();
		Warlock( const Warlock &w );

		Warlock&	operator=( const Warlock &w );
};

#endif