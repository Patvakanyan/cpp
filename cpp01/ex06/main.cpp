#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl h;

	if( argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}
	h.complain(argv[1]);
	return 0;
}
