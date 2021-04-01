
#include "Weapon.hpp"
#include "HumanB.hpp"
#include "HumanA.hpp"

int		main()
{
	{
		Weapon	club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("big long club");
		bob.attack();
	}
	{
		Weapon	club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("big long club");
		jim.attack();
	}
}