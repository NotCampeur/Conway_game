#include "Zombie.hpp"
#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde	students(105);

	students.announce();
	students[104].announce();
	return 0;
}