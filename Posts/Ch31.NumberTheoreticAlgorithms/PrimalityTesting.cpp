
#include <cmath>
#include <cassert>
#include <cstdlib>
#include "Mod.hpp"
#include "PrimalityTesting.hpp"
#include "ModularExponentiation.hpp"


bool TrialDivision(int n) {
   int k = floor(sqrt(n)); 
   for (int i=2; i<k+1; i++) {
      if (n%i == 0) {
         // composite
         return true;
      }
   }
   // prime
   return false;
}

bool PseudoPrime(int n) {
   int d = ModularExponentiation(2, n-1, n);
   if (d!=1) {
      // composite
      return true;
   }
   // hope prime
   return false;
}

static bool witness(int a, int n) {
   assert(n&1); // n shall be odd
   //https://medium.com/@manishsakariya/finding-position-of-first-least-significant-non-zero-bit-in-binary-number-6df144602f89 
   int t = (n-1) & ~(n-1-1) - 1;
   int u = (n-1)>>t;

   int x = ModularExponentiation(a, u, n);
   for (int i=0; i<t+1; i++) {
      int xp = x;
      x = Mod(x*x, n);
      if (x==1 && xp!=1 && xp!=n-1) 
         return true;
   }
   if (x!=1)
      return true;
   return false;
}

bool MillerRabin(int n, int s)
{
   for (int j=0; j<s; j++) {
      int a = random() % n;
      if(witness(a,n))
         // definitely composite
         return true;
   }
   // almost surely prime
   return false;
};
