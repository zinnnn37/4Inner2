#include "ATarget.hpp"

ATarget::ATarget() {}

ATarget::ATarget( std::string type )
	: _type(type)
{
}

ATarget::ATarget( const ATarget &a )
{
	*this = a;
}

ATarget::~ATarget() {}

ATarget&	ATarget::operator=( const ATarget& at )
{
	if (this != &at)
		this->_type = at.getType();

	return (*this);
}

const std::string&	ATarget::getType() const
{
	return (this->_type);
}

void	ATarget::getHitBySpell( const ASpell& as ) const
{
	std::cout << this->_type << " has been " << as.getEffects() << "!" << std::endl;
}
