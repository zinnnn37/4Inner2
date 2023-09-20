#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>

class	Warlock
{
	private:
		const std::string	name;
		std::string			title;

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
};

#endif