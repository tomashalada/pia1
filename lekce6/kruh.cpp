#include <vector>
#include <iostream>
#include <cmath>

using parametr = float;
struct Kruh
{
    Kruh() = default;
    Kruh(parametr r)
    {
        radius = r;
    }

    void setRadius(parametr r)
    {
        radius = r;
        
    }
    void vypisUdaje()
    {
        std::cout << "Radius je:" << radius << std::endl;
        std::cout << "Plocha kruhu:" << spocitejPlochu() << std::endl;
        std::cout << "Obvod kruhu:" << spocitejObvod() << std::endl;
    }
    parametr spocitejPlochu()
    {
        return  pi * pow(2, radius);
        
    }
    parametr spocitejObvod()
    {
        return (parametr)2 * pi * radius;
    }
private:

    parametr radius;
    const parametr pi = (parametr)3.14;

};

int main()
{
    float prvniRadius = 2;
    Kruh prvniKruh;
    prvniKruh.setRadius(prvniRadius);

    float druhyRaidus = 4;
    Kruh druhyKruh(druhyRaidus);
    std::cout << "Plocha kruhu:" << prvniKruh.spocitejPlochu() << std::endl;
    std::cout << "Obvod kruhu:" << prvniKruh.spocitejObvod() << std::endl;

    druhyKruh.vypisUdaje();

    // BONUS: radius kruhu bude sablonovy parametr, a udela pole kruhu a pro kazdy kruh spocita vse

    return 0;
}
