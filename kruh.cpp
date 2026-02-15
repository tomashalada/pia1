#include <iostream>
#include <cmath>

class Kruh
{
    public:
    void setRadius(float newRadius)
    {
        radius=newRadius;
    }
    int getRadius()
    {
        return radius;
    }
    // void print()
    // {
    //     std::cout <<"Radius je: " <<radius<< std::endl;
    // }
    float spocitejPlochu()
    {
        return 3.14* radius * radius;
    }
    float spocitejObvod()
    {
        return 2*3.14* radius;
    }
    void vypisUdaje()
    {
        std::cout << "Radius:" << radius << std::endl;
        std::cout << "Obvod:" << spocitejObvod() << std::endl;
        std::cout << "Plocha:" << spocitejPlochu() << std::endl;
    }
   private:

      float radius;
};

int main()
{
   float prvniRadius = 2;
   Kruh prvniKruh;
   prvniKruh.setRadius( prvniRadius );
   std::cout << "Radius:" << prvniKruh.getRadius() << std::endl;
   std::cout << "Obvod kruhu:" << prvniKruh.spocitejObvod() << std::endl;
   std::cout << "Plocha kruhu:" << prvniKruh.spocitejPlochu() << std::endl;
   float druhyRadius = 4; 
   Kruh druhyKruh;
   druhyKruh.setRadius(druhyRadius);
   druhyKruh.vypisUdaje();

   // BONUS: radius kruhu bude sablonovy parametr, a udela pole kruhu a pro kazdy kruh spocita vse

   return 0;
}