# Lekce 1

#### Kompilace:

- Lexikografická analýza, parsování, semantická analýza, optimalizace a generování kódu
- Hlavní rozdíl je v tom kdy a jak se kód překládá do strojového kódu
- Kompilování: Preprocessing, statická analýza, kontrola typů, optimalizace (inlining, loop unrolling, dead code removal, reigster allocation, constant folding and propagation)
- Binárky běží přímo na hw s minimálním overheadem, efektivní nízkoúrovňová správa paměti
- Predictable: branch prediction, cache utilization

#### Interpretace:

- Parsování a spouštění kódu dynamicky (kód je převeden do abstract syntax tree representace, převedena do bytecode)
- Dynamické typování vyžaduje časté přístupy do hash tabulky
- Automatická správa paměti, obtížná dopředná optimalizace
- Interpreter napsaný v C
- (zhruba 100x víc CPU cyků na operaci)


#### Elementary example
