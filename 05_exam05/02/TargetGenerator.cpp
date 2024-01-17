#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator( const TargetGenerator& tg )
{
	(void)tg;
}

TargetGenerator::~TargetGenerator() {}

TargetGenerator&	TargetGenerator::operator=( const TargetGenerator& tg )
{
	(void)tg;

	return (*this);
}

void	TargetGenerator::learnTargetType( ATarget* at )
{
	TargetGenerator::Iter	it = this->_targets.find(at->getType());

	if (it == this->_targets.end())
		this->_targets.insert( TargetGenerator::Pair(at->getType(), at->clone()) );
}

void	TargetGenerator::forgetTargetType( const std::string& target )
{
	TargetGenerator::Iter	it = this->_targets.find(target);

	if (it != this->_targets.end() )
	{
		this->_targets.erase(target);
		delete it->second;
	}
}

ATarget*	TargetGenerator::createTarget( const std::string& target )
{
	TargetGenerator::Iter	it = this->_targets.find(target);

	if (it != this->_targets.end())
		return (it->second->clone());

	return (NULL);
}