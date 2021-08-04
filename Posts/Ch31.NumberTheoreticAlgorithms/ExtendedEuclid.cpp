#include <tuple>
#include <iostream>
#include "ExtendedEuclid.hpp"
#include "Mod.hpp"

std::tuple<int, int, int> ExtendedEuclid(int a, int b)
{
	if (b == 0) {
		return std::make_tuple(a, 1, 0);
	} else {
		auto t = ExtendedEuclid(b, Mod(a,b));
		int dt = std::get<0>(t);
		int xt = std::get<1>(t);
		int yt = std::get<2>(t);

		int d = dt;
		int x = yt;
		int y = xt - a/b*yt;
		return std::make_tuple(d, x, y);
	}
}
