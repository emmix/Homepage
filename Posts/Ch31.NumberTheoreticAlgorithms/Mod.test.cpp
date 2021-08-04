#include <tuple>
#include <iostream>
#include "Mod.hpp"

int main() {
	std::cout<<Mod(99,78)<<std::endl;
	std::cout<<Mod(4,2)<<std::endl;
	std::cout<<Mod(-21,4)<<std::endl;
	std::cout<<Mod(-21,-4)<<std::endl;
	std::cout<<Mod(21,-4)<<std::endl;

	return 0;
}
