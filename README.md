# Programování Inženýrských Aplikací I (PIA I), ZS 2025/2026

Stručný soubor poznámek a soubor odkazů z hodin.
Podklady z předchozích ročníků jsou k dispozici na [Moodle](https://moodle-vyuka.cvut.cz/course/view.php?id=14467).

Pro splnění je požadováno plnění jednotlivých úkolů v průběhu semestru, vypracování celosemestrálního projketu (skupiny po dvou, třech) a splnění závěrečného testu.
Návrhy semestrálních prací pro inspiraci najdete třeba [zde](https://github.com/tomashalada/pia1).

## Obsah předmětu

Stručný přehled probírané látky včetně užitečných odkazů

### Lekce 1

- Osnova, PIA I, PIA II

- Linux: Linux jako hlavní OS, dualboot, subsystém
   - Proč potřebujeme znát linux?
   - [Základní příkazy na linuxu](https://swcarpentry.github.io/shell-novice/)

- Programovací jazyky pro průmyslové aplikace
   - Benefity C, C++, Fortranu oproti pythonu
   - Julie, Matlab

- Editor, standardy psaní kódu a poučky Kuby Klinkovského

- Git
   - [Git stručně](https://jlk.fjfi.cvut.cz/teaching/PROP_2024/git.html) od Jakuba Klinkovského z KSI FJSI:

- Struktura C++ programů
- Kompilování kódu (co dělá překladač)

- Základní datové typy I.

- Představení semestrálních projektů (skupiny po 2, 3 lidech)
   - Vše na githubu
   - Příspěkvy přes merge requesty

#### Užitečné odkazy a doplňující zdroje:

- [Kurz programování ZPRO (python) na KSI FJFI](https://gitlab.fjfi.cvut.cz/ksi/zpro-2024-public)
- [Základní poznámky k programování od Jakuba Klinkovského z FJFI (PROG)](https://jlk.fjfi.cvut.cz/teaching/PROP_2023.html)
- __(Nainstaluj!)__ Instalace [VSCodium](https://vscodium.com/)/[VSCode](https://code.visualstudio.com/) včetně rozšíření [podle návodu ze ZPRO na KSI FJFI](https://gitlab.fjfi.cvut.cz/ksi/zpro-2024-public/-/blob/main/10%20VSCodium.ipynb?ref_type=heads)
- __(Nainstaluj!)__ Linux nebo subsystém [WSL](https://learn.microsoft.com/en-us/windows/wsl/install) - Nebojte, nedá se pokazit nic! Alternativně lze použít [MSYS2: Software Distribution and Building Platform for Windows](https://www.msys2.org/)
- Doporučené linuxové distribuce pro začátek: Ubuntu (Kubuntu, Xubuntu, Lulubuntu) - Nebojte, nedá se pokazit moc!
- __(Nainstaluj!)__ [Git](https://git-scm.com/) nebo [Git pro Windows](https://gitforwindows.org/) - doporučuji např. [instrukce k instalaci](https://carpentries.github.io/workshop-template/install_instructions/#shell)
- [Git ve VSCode terminálu](https://code.visualstudio.com/docs/sourcecontrol/intro-to-git#_using-git-in-the-builtin-terminal)
- [Unix Shell Tutorial](https://swcarpentry.github.io/shell-novice/)

---

### Lekce 2

- Základní příkazy na linuxu II
   - struktura linuxových systémů

- Základní datové typy II.
   - Aritmetika - vliv konečné aritmetiky, redukované aritmetiky a moderní výpočetní jednotky
   - První náznak šablon (možná)
   - Literály a static_cast

- Alokace a správa paměti.
   - Jak vypadá procesor, co jsou to cache, RAM, a proč to potřebujeme vědět

- Cykly a funkce pro větvení programu

- Výběr a přihlášení semestárlních projektů
   - Skupiny se přihlásí přes git

#### Užitečné odkazy:
- EEEI standard konečné artimetiky - kalkulačka: https://www.h-schmidt.net/FloatConverter/IEEE754.html

---

### Lekce 3

- Statické a dynamické pole
   - datové konejnery [std::vector](https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/) (alternativně [zde](https://learn.microsoft.com/cs-cz/cpp/standard-library/vector-class?view=msvc-170)) a [std::array](https://www.geeksforgeeks.org/cpp/stdarray-in-cpp/) (alternativně [zde](https://learn.microsoft.com/cs-cz/cpp/standard-library/array-class-stl?view=msvc-170))
- Reference a pointery

---

### Lekce 4

- Vícerozměrné pole
- Funkce

__PREZENTACE SKUPINOVÝCH PROJEKTŮ__ (přesunuto z lekce 3): Popsání vybraného projektu, co je vstup, co je výstup, jaké kroky a procesy musí program obsahovat.
3-5 minut, prezentace (stačí 1/2 slide) či na tabuli.
__ÚKOL (DOPORUČENÝ):__ Lineární advekce.

---

### Lekce 5

- Opakování základních konceptů (výpis, pole, funkce, cykly, podmínky).

- (Přesunuto): Smart pointery
- (Přesunuto): Knihovna STD I.
- (Přesunuto): Lambda funkce I.

- [Datové kontejnery standardní knihovny](https://www.geeksforgeeks.org/cpp/containers-cpp-stl/)
- [Datové kontejnery - detailní přehled](https://cplusplus.com/reference/stl/)

---

### Lekce 6

- Objektově orientované programování I: Třídy a struktury
   - úvod
   - data a member functions třídy
   - koncept vlastnictví

- [Odkaz na úvod do objektově orientovaného programování v C++](https://www.geeksforgeeks.org/cpp/object-oriented-programming-in-cpp/)
- [Detailnější úvod do C++ tříd](https://cplusplus.com/doc/tutorial/classes/) a ještě jeden [alternativní zdroj s ukázkou možností tříd a struktur](https://learn.microsoft.com/en-us/cpp/cpp/classes-and-structs-cpp?view=msvc-170)

- (Doplňkové): Šablonové programování: Ukázky k šablonám jsou v adresáři: `concepts/templates`
      Dále pak:
      -  https://learn.microsoft.com/en-us/cpp/cpp/templates-cpp?view=msvc-170

__ÚKOL (POVINNÝ):__ Ve složce 6 lekce najdete [neúplný kód implementující třídu kruh](https://github.com/tomashalada/pia1/blob/main/lekce6/kruh.cpp).
Doplňte příslušné funkce pro výpočet obvodu a obsahu, konstruktory a nastavení poloměru.
Výsledek nahrajte do vlastního repozitáře.

---

### Lekce 7


- Objektově orientované programování II: Třídy a struktury
   - přetěžování operátorů ([ukázka](https://github.com/tomashalada/pia1/blob/main/lekce6/matrix.cpp))
   - dědičnost
   - (pohádka o) šablonové programování
- Referenční kontrola samosatných prací

__PREZENTACE SKUPINOVÝCH PROJEKTŮ__ (přesunuto z lekce 3): Popsání vstupu a výstupu, pseudokód a rozvržení vytvářeného programu. Jaké algoritmizační a programové prvky budete používat.
3-5 minut, prezentace (stačí 1/2 slide) či na tabuli.

---

### Lekce 8

- Objektově orientované programování II: Třídy a struktury
   - dědičnost
   - (pohádka o) šablonové programování

- Co dělá překladač a jeho dodatečné argumenty
- Kompilace pomocí `CMake` a `make`, členění a struktura programu

- [Tutoriál k práci s CMake](https://hsf-training.github.io/hsf-training-cmake-webpage/01-intro/index.html), případně [oficiální návod pro práci s CMake](https://cmake.org/cmake/help/latest/guide/tutorial/index.html)
- [Minimalistická ukázka práce s Makefile](https://www.geeksforgeeks.org/cpp/makefile-in-c-and-its-applications/)

---

### Lekce 9

- Externí/výpočetní servery, clustery a úložiště


### Lekce 10


### Lekce 11


### Lekce 12

- Prezentace semestrálních prací

### Lekce 13

- Bonus: HPC, numerické počítání, moderní a rychlé architektury a jejich použití
  (Poznánka na PIA II)
- Datové struktury pro numerické počítání

### Zařadit

- Algoritmy a třídy složitosti (N vs NP)
- Testování: Unit testy, regression testy, knihovny na testování
- Základní numerické knihovny
- Make a CMake
- zpracování chyb - výjimky, assert
- Pokročilé datové struktury
