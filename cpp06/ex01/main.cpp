#include "Serializer.hpp"
#include <iostream>
#include "Data.hpp"
#include <stdint.h>

int main()
{
	Data d;
	d.x = 42;

	Data *ptr = &d;

	uintptr_t raw = Serializer::serialize(ptr);
	Data *restored = Serializer::deserialize(raw);

	std::cout << restored->x << std::endl;
}
