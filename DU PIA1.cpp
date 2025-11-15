// main.cpp
#define _USE_MATH_DEFINES        // kvůli M_PI v MSVC
#include <iostream>
#include <cmath>                  // M_PI

class Kruh {
private:
    float radius;

public:
    // Konstruktor (výchozí radius = 0)
    explicit Kruh(float r = 0.0f) : radius(r) {}

    // Setter / Getter
    void setRadius(float r) { radius = r; }
    float getRadius() const { return radius; }

    // Výpočet plochy
    float spocitejPlochu() const {
        return static_cast<float>(M_PI) * radius * radius;
    }

    // Výpočet obvodu
    float spocitejObvod() const {
        return 2.0f * static_cast<float>(M_PI) * radius;
    }

    // Výpis informací
    void vypisUdaje() const {
        std::cout << "Radius: " << radius << '\n'
                  << "Plocha: " << spocitejPlochu() << '\n'
                  << "Obvod:  " << spocitejObvod()  << "\n\n";
    }
};

int main() {
    // 1) Ukázka s jednotlivými objekty
    Kruh prvni(2.0f);
    Kruh druhy(4.0f);

    std::cout << "Plocha prvniho kruhu: " << prvni.spocitejPlochu() << '\n';
    std::cout << "Obvod  prvniho kruhu: " << prvni.spocitejObvod()  << "\n\n";

    std::cout << "Druhy kruh:\n";
    druhy.vypisUdaje();

    // 2) Pole kruhu
    const int pocetKruhu = 3;
    Kruh pole[pocetKruhu] = { Kruh(1.0f), Kruh(3.0f), Kruh(5.0f) };

    for (int i = 0; i < pocetKruhu; ++i) {
        std::cout << "Kruh " << (i + 1) << ":\n";
        pole[i].vypisUdaje();
    }

    // Pokud se ti konzole po dobehu hned zavira, odkomentuj:
    // system("pause");

    return 0;
}
