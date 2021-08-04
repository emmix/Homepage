
all: PrimalityTesting.test PollardRho.test Mod.test ExtendedEuclid.test ModularLinearEquationSolver.test ModularExponentiation.test

PrimalityTesting.test: Mod.cpp Euclid.cpp ModularExponentiation.cpp PrimalityTesting.cpp PrimalityTesting.test.cpp
	g++ -std=c++11 $^ -o $@ 

PollardRho.test: Mod.cpp Euclid.cpp PollardRho.cpp PollardRho.test.cpp
	g++ -std=c++11 $^ -o $@ 

ModularExponentiation.test: Mod.cpp ModularExponentiation.cpp ModularExponentiation.test.cpp
	g++ -std=c++11 $^ -o $@ 

Mod.test: Mod.cpp Mod.test.cpp
	g++ -std=c++11 $^ -o $@ 
ModularLinearEquationSolver.test: Mod.cpp ExtendedEuclid.cpp ModularLinearEquationSolver.cpp ModularLinearEquationSolver.test.cpp
	g++ -std=c++11 $^ -o $@ 
ExtendedEuclid.test: Mod.cpp ExtendedEuclid.cpp ExtendedEuclid.test.cpp
	g++ -std=c++11 $^ -o $@ 
