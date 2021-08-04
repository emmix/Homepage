
#include <iostream>
#include <cmath>
#include "Mod.hpp"

int Euclid(int a, int b) {
	if (b == 0) {
		return a;
	} else {
		return Euclid(b, Mod(a,b)); 
	}
}
