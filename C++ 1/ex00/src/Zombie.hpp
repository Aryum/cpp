#ifndef ZOMBIE_HPP
#	define ZOMBIE_HPP

#include <string>
#include <iostream>

#define WHITE "\033[0m"
#define GREEN "\033[1;32m"
#define MAGENTA "\033[1;35m"
#define RED "\033[1;31m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"

class Zombie
{
	public:
		Zombie();
		Zombie(std::string name);
		Zombie(const Zombie &other);
		Zombie &operator=(const Zombie &other);
		~Zombie();
		void announce(void);

	private:
		std::string _name;
};

Zombie* newZombie(std::string name);

void randomChump(std::string name);

#endif