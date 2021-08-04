
#include <iostream>
#include "PrimalityTesting.hpp"

int main()
{
   std::cout<<TrialDivision(561)<<" "<<TrialDivision(1729)<<" "<<TrialDivision(73)<<std::endl;
   std::cout<<PseudoPrime(561)<<" "<<PseudoPrime(1729)<<" "<<PseudoPrime(73)<<std::endl;
   std::cout<<MillerRabin(561, 50)<<" "<<MillerRabin(1729, 50)<<" "<<MillerRabin(73, 50)<<std::endl;

   return 0;
}
