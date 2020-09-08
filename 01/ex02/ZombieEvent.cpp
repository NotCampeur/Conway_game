#include "ZombieEvent.hpp"

// CONSTRUCTORS | DESTRUCTOR
		ZombieEvent::ZombieEvent()
{
	_type = Zombie::ZombieType::basic;
}

Zombie	ZombieEvent::randomChump(void)
{
	Zombie result;

	result.set_type(_type);
	result.rand_name_gen();
	result.announce();
	return result;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *result;

	result = new Zombie(_type, name);
	return result;
}

		ZombieEvent::~ZombieEvent()
{

}

// ACCESSORS
void	ZombieEvent::setZombieType(Zombie::ZombieType type)
{
	_type = type;
}