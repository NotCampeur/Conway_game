#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int			main()
{
	ZombieEvent event;
	Zombie		randomZombie;
	Zombie		eventLessZombie(static_cast<Zombie::ZombieType>(2), "Tom");
	Zombie		buggedZombie(static_cast<Zombie::ZombieType>(-42), "dumb");
	Zombie		*heapZombie;

	srand(time(NULL));
	eventLessZombie.announce();
	buggedZombie.announce();
	event.setZombieType(static_cast<Zombie::ZombieType>(rand()%9));
	randomZombie = event.randomChump();
	event.setZombieType(static_cast<Zombie::ZombieType>(rand()%9));
	heapZombie = event.newZombie("Charles");
	heapZombie->advert();
	delete heapZombie;
	return 0;
}