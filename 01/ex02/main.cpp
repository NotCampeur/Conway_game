#include "Zombie.hpp"
#include "ZombieEvent.hpp"

int			main()
{
	ZombieEvent event;
	Zombie		randomZombie;
	Zombie		eventLessZombie(static_cast<Zombie::ZombieType>(rand()%9), "Tom");
	Zombie		*heapZombie;

	srand(time(NULL));
	eventLessZombie.announce();
	event.setZombieType(static_cast<Zombie::ZombieType>(rand()%9));
	randomZombie = event.randomChump();
	event.setZombieType(static_cast<Zombie::ZombieType>(rand()%9));
	heapZombie = event.newZombie("Lomard");
	heapZombie->advert();
	delete heapZombie;
	return 0;
}