#ifndef ZOMBIE_H
# define ZOMBIE_H
# include <iostream>
# include <string>

class Zombie
{
  public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void setName(const std::string &name) ;
	void announce(void);

  private:
	std::string name;
};
Zombie* zombieHorde(int N, const std::string &name );
#endif
