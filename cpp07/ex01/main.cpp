#include "iter.hpp"
#include <iostream>
int main()
{
	int arr[] = {0,1,2,3,4};
	const size_t size = 5 ;
	iter(arr, size, print<int>);
	std::cout<<"----------------------"<<std::endl;
	iter(arr, size, pow<int>);
	iter(arr, size, print<int>);
}
