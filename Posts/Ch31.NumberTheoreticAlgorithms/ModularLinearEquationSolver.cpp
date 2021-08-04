
#include "ModularLinearEquationSolver.hpp"
#include "ExtendedEuclid.hpp"
#include "Mod.hpp"

void ModularLinearEquationSolver(int a, int b, int n)
{
	auto t = ExtendedEuclid(a, n);
	int dt = std::get<0>(t);
	int xt = std::get<1>(t);
	int yt = std::get<2>(t);
	//std::cout<<"(d,x',y')="<<dt<<","<<xt<<","<<yt<<std::endl;

	if (b%dt == 0) {
		int x0 = Mod(xt*(b/dt),n);
		for (int i=0; i<dt; i++) {
			std::cout << Mod(x0+i*(n/dt),n) << " ";
		}
	} else {
		std::cout<<"no solution";
	}
	std::cout<<std::endl;
}
