#include <tuple>
#include <iostream>
#include "ExtendedEuclid.hpp"

int main() {
	auto t = ExtendedEuclid(99,78);
	std::cout<<std::get<0>(t)<<" "<<std::get<1>(t)<<" "<<std::get<2>(t)<<std::endl;

	t = ExtendedEuclid(-99,78);
	std::cout<<std::get<0>(t)<<" "<<std::get<1>(t)<<" "<<std::get<2>(t)<<std::endl;
}
