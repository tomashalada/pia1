#include <include>

class Kruh
{
   private:

      float radius;
}

int main()
{
   float prvniRadius = 2;
   Kruh prvniKruh;
   prvniKruh.setRadius( prvniRadius );

   float druhyRaidus = 4;
   Kruh druhyKruh( druhyRaidus );
   std::cout << "Plocha kruhu:" << prvniKruh.spocitejPlochu() << std::stdl;
   std::cout << "Obvod kruhu:" << prvniKruh.spocitejObvod() << std::stdl;

   druhyKruh.vypisUdaje();

   // BONUS: radius kruhu bude sablonovy parametr, a udela pole kruhu a pro kazdy kruh spocita vse

   return 0;
}
