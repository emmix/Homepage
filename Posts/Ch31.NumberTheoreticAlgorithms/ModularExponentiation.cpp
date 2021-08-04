
#include <cassert>
#include <iostream>
#include "Mod.hpp"
#include "ModularExponentiation.hpp"

// a^b (mod n)
int ModularExponentiation(int a, int b, int n)
{
	assert(a>=0);
	assert(b>=0);
	assert(n>0);

	int c = 0;
	int d = 1;
	
	int k = sizeof(b)*8 - 1;
	for (int i=0; i<k+1; i++) {
		c = 2*c;
		d = Mod(d*d, n);
		int bi = (b>>(k-i)) & 1;
		if (bi==1) {
			c = c+1;
			d = Mod(d*a, n);
		}
		//std::cout<<bi<<" "<<c<<std::endl;
	}

	return d;
}

