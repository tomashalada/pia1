# Lekce 1


## Úkol:

Do souboru `gitTest.txt` v tomto adresáři (`pia1/lekce1/gitTest.txt`) doplňte potvrzení ke svému jménu. Využijte přitom postup fork, clone, edit, commit, push.

#### Návod:

Níže je stručný postup, jak úkol realizovat, včetně generování a přidání SSH klíče pro Váš Github účet.
Více o Gitu je uvedeno v dokazech na [na úvodní stránce](https://github.com/tomashalada/pia1/blob/main/README.md).

1. **Vygenerování SSH klíče**:
   - Otevřete terminál (Linux/Mac) nebo Git Bash (Windows).
   - Zadejte příkaz:
     ```bash
     ssh-keygen -t ed25519 -C "vas_email@example.com"
     ```
     (Pokud máte starší systém, použijte `-t rsa` místo `-t ed25519`.)
   - Stiskněte Enter pro výchozí umístění souboru (`~/.ssh/id_ed25519`) a případně zadejte heslo (lze nechat prázdné).
   - Zobrazte veřejný klíč:
     ```bash
     cat ~/.ssh/id_ed25519.pub
     ```
   - Zkopírujte výstup (veřejný klíč).

2. **Přidání SSH klíče na GitHub**:
   - Přihlaste se na GitHub (https://github.com).
   - Klikněte na svůj profil (vpravo nahoře) → **Settings** → **SSH and GPG keys** → **New SSH key** nebo **Add SSH key**.
   - Pojmenujte klíč (např. "PIA1") a vložte zkopírovaný veřejný klíč do pole.
   - Klikněte na **Add SSH key**.

3. **Fork repositáře**:
   - Přejděte na https://github.com/tomashalada/pia1.
   - Klikněte na tlačítko **Fork** (vpravo nahoře) a vytvořte kopii repositáře ve vašem GitHub účtu.

4. **Naklonování forknutého repositáře**:
   - Zkopírujte SSH adresu vašeho forku (např. `git@github.com:vas-uzivatel/pia1.git`).
   - V terminálu zadejte:
     ```bash
     git clone git@github.com:vas-uzivatel/pia1.git
     ```
   - Přejděte do složky:
     ```bash
     cd pia1
     ```

5. **Úprava souboru gitTest.txt**:
   - Otevřete soubor `lekce1/gitTest.txt` v textovém editoru.
   - Najděte své jméno a přidejte za něj ` OK` (např. `Išván Evženovič OK`).
   - Uložte změny.

6. **Commit a push změn**:
   - Přidejte změněný soubor do sledování:
     ```bash
     git add lekce1/gitTest.txt
     ```
   - Vytvořte commit:
     ```bash
     git commit -m "Přidáno OK k mému jménu"
     ```
   - Nahrajte změny do svého forku:
     ```bash
     git push origin main
     ```

7. **Vytvoření Merge Requestu**:
   - Přejděte na váš fork na GitHubu (https://github.com/vas-uzivatel/pia1).
   - Klikněte na **Contribute** → **Open pull request** (nebo uvidíte notifikaci o vašich změnách s možností vytvořit pull request).
   - Zkontrolujte, že cílový repositář je `tomashalada/pia1` a větev `main`.
   - Pojmenujte pull request (např. "Přidání OK k jménu Ištván Evženovič") a klikněte na **Create pull request**.

**Poznámky**:
- Ujistěte se, že máte nainstalovaný Git (`git --version` pro kontrolu).
- Pokud SSH nefunguje, zkontrolujte konfiguraci: `ssh -T git@github.com` (mělo by vrátit potvrzení přihlášení).
- Při problémech s SSH můžete dočasně použít HTTPS adresu repositáře, ale SSH je preferováno.

## Poznámky:

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

#### Elementární ukázka
