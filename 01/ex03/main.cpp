#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde	students(105);

	srand(time(NULL));
	students.announce();
	return 0;
}