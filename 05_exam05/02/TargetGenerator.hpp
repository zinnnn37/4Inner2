#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

class	ATarget;

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include "ATarget.hpp"

class	TargetGenerator
{
	private:
		typedef	std::map< std::string, ATarget * >	Map;
		typedef	std::pair< std::string, ATarget * >	Pair;
		typedef	Map::iterator						Iter;

		Map		_targets;

		TargetGenerator( const TargetGenerator& tg );

		TargetGenerator&	operator=( const TargetGenerator& tg );

	public:
		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType( ATarget* at );
		void		forgetTargetType( const std::string& target );
		ATarget*	createTarget( const std::string& target );
};

#endif