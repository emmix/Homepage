
#include <cstdlib>
#include <iostream>
#include "Euclid.hpp"
#include "Mod.hpp"
#include "PollardRho.hpp"


void PollardRho(int n)
{
   int i = 1;
   int x = random() % n;
   //int x = 2;
   int y = x;
   int k = 2;
 
   while (true) {
     i = i+1;
     std::cout<<"x: "<<x<<std::endl;
     x = Mod((x*x-1),n);
     int d = Euclid(y-x, n); 
     if (d!=1 && d!=n) {
        std::cout<<d<<std::endl;
     }

     if(i == k) {
        y = x;
        k = 2*k;
     }
   }
}

void FloydPollardRho(int n)
{
   int i = 1;
   int x = random() % n;
   //int x = 1186;
	//int x = 2;
   int xx = x;
   int y = x;
   int k = 2;
	int times = 0;
 
   std::cout<<x<<" "<<xx<<std::endl;
   do {
     i = i+1;
     x = Mod((x*x-1),n);
     xx = Mod((xx*xx-1),n);
     xx = Mod((xx*xx-1),n);
     std::cout<<x<<" "<<xx<<std::endl;
     int d = Euclid(y-x, n); 
     if (d!=1 && d!=n) {
        std::cout<<d<<std::endl;
     }

     if(i == k) {
        y = x;
        k = 2*k;
     }
	  if (x == xx) times++;
   }while (times<3);
}
