
#include <iostream>
#include <cassert>
#include <cmath>
#include "Mod.hpp"

// refer to P75
// https://stackoverflow.com/questions/13683563/whats-the-difference-between-mod-and-remainder
int Mod(int a, int b)
{
	return a - std::floor(float((a*1.0)/(b*1.0)))*b;
}
