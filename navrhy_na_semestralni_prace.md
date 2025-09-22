## Numerické úlohy:

Pro vybraný systém (rovnice mělké vody, Eulerovi rovnice, rovnice vedení tepla, vlnová rovnice, rovnice vedení tepla, systém ODE), implementujte řešení jednoduché pomocí vybrané numerické metody (metoda konečných diferencí, bezsíťová metoda konečných diferencí, metoda konečných objemů, metoda konečných prvků)
- Rovnice mělké vody - kachničky: https://doi.org/10.1017/jfm.2021.820

## Zpracování obrazu: Najděte dron
V obrazu (či videu) z fotoaparátu (či kamery) identifikujte letící dron. Identifikace by měla být rychlá a efektivní. Na základě polohy dronu můžete dopočítat jak zaměřit sestřelovací zařízení.

## Zpracování obrazu: Segmentace či trasování buněk v buněčené biologii
Ve snínmku z mikroskopu (https://www.mpi-cbg.de/) segmentujte jednotlivé buňky nebo tkáňová rozhraní.
Případně se můžete pokusit ze záznamu z mikroskopu pokusit určit trajektorie jednotlivých buněk.

## MNIST from scratch - program na rozpoznávání ručně psaných čísel
Implementujte jednoduchou neuronovou síť (bez použití externích knihoven), která je schopna naučit se rozpoznávat rukou psaná čísla.

## Kartézská síť a vnořená geometrie
Uvažujte kartézskou výpočetní síť, skládající se z pravidelných buněk. Do této sítě vnořte křivočarou geometrii. Pro každou z kartézských buněk určete, zda se v ní nachází hranice vnořené geometrie a pokud ano, uložte pro danou buňku poměr obsazenosti a normálu k vnořené geometrii. Doporučuji využít knihovny VTK.

## Zpracování zvukového záznamu
Načtěte a filtrujte či modulujte zvukový záznam. Výsledek opět exportujte.

## Efektivní vizualizace dat přímo z C++ (vlastní, ascent, VTK)
V řadě velkých numerických simulací vizualizujeme výsledky tak, že data uložíme a poté vizualizujeme v rámci dodatečného zpracování.
To v řadě případů znamená ukládání velkého množství dat, jejich opětovné načítání apod.
Implementujte funkci či nástroj, který dokáže vygenerovat obrázek simulace přímo z C++ výpočetního kódu.

## Aplikace s grafickým rozhraním (například knihovna Qt)
Pro vybranou aplikaci (dle vlastního výběru, vylepšení stávající aplikace) vytvořte grafické rozhraní.
Doporučuji pracovat s knihovnou Qt.

## Route planner - vylepšení
Vylepšení existujícího projektu s využitím prohledávacího algoritmu (prohledávání do hloubky/A*) na importovaných reálných datech (linky MHD, cesty z openstreetmap). Můžete např. vytvořit grafické rozhraní, vylepšit efektivitu prohledávání apod.

## Rozvoj existujícího kódu: Implementace schémat pro časovou integraci

TNL-SPH je pokročilý kód pro numerické výpočty proudění (zejména proudění s volnou hladinou) pomocí částicových metod, využívající masivně paralelní výpočty na GPU.
Namísto diskretizace využívající síť využívá lagrangeovských částic bez vzájemných topologických vazeb.
Pro vývoj systému v čase potřebujeme určit trajektorie částic - děje se tak pomocí integrace pohybových rovnic.
V poslední době se ukazuje, že zaběhlé způsoby časové integrace v částicových metodách možná nejsou úplně nejefektivnější a jiná integrační schémata vedou k přesnějším či rychleji získaným řešením.
K existujícím časově integračním schématům v TNL-SPH dopimplementujte další a otestujte je.

## Rozvoj existujícího kódu: Template Numerical Library issue
- Vyřeště některé z issues v rámci Template Numerical Library knihovny: https://gitlab.com/groups/tnl-project/-/issues (v adekvátním rozsahu)
- Vyřeště některé z issues v rámci některého z numerických submodulů TNL knihovny (TNL-LBM, TNL-SPH, TNL-MHFEM, TNL-FVM (nové!))

## Rozvoj existujícího kódu: Open Source
- Vyřeště nějaké z issue v rámci nějakého open source projektu (v adekvátním rozsahu).

## Programování pro konkrétní HW: Arduino, embedded zařízení

## Navrhněte vlastní téma
