#include <iostream>
#include <cmath>  // Pro konstantu M_PI

class Kruh
{
private:
    float radius;

public:
    // Konstruktor pro inicializaci radiusu
    Kruh(float r = 0) : radius(r) {}

    // Nastavení radiusu
    void setRadius(float r)
    {
        radius = r;
    }

    // Výpočet plochy
    float spocitejPlochu() const
    {
        return M_PI * radius * radius;
    }

    // Výpočet obvodu
    float spocitejObvod() const
    {
        return 2 * M_PI * radius;
    }

    // Výpis údajů o kruhu
    void vypisUdaje() const
    {
        std::cout << "Radius: " << radius << std::endl;
        std::cout << "Plocha: " << spocitejPlochu() << std::endl;
        std::cout << "Obvod: " << spocitejObvod() << std::endl;
    }
};

int main()
{
    float prvniRadius = 2;
    Kruh prvniKruh;
    prvniKruh.setRadius(prvniRadius);

    float druhyRadius = 4;
    Kruh druhyKruh(druhyRadius);

    std::cout << "Plocha prvního kruhu: " << prvniKruh.spocitejPlochu() << std::endl;
    std::cout << "Obvod prvního kruhu: " << prvniKruh.spocitejObvod() << std::endl;

    druhyKruh.vypisUdaje();

    // BONUS: Šablonový parametr pro radius, pole kruhů
    const int pocetKruhu = 3;
    Kruh poleKruhu[pocetKruhu] = { Kruh(1), Kruh(3), Kruh(5) };

    for (int i = 0; i < pocetKruhu; ++i)
    {
        std::cout << "Kruh " << i + 1 << ":" << std::endl;
        poleKruhu[i].vypisUdaje();
    }

    return 0;
}
