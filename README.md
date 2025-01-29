# Housenka a Zelený svět

## Popis zadání

Cílem tohoto projektu je vytvořit hru, ve které hráč ovládá housenku pohybující se
po hracím poli o rozměrech 40x20. Úkolem hráče je sbírat zelí, které se náhodně objevuje
na herním poli. Každé sebrané zelí přidává body a prodlužuje délku housenky,
čímž se hra postupně stává náročnější. Hra končí, pokud housenka narazí do okraje hracího
pole nebo sama do sebe.

## Kompilace a spuštění programu

Program lze zkompilovat následujícím příkazem:

pro WINDOWS
```bash
g++ -o game main.cpp inputHandler/InputHandler_Linux.cpp model/Caterpillar.cpp model/GameField.cpp model/GameLoop.cpp model/Point.cpp render/Renderer.cpp
./game
```

pro LINUX
```bash
mkdir build
cd build
cmake ..
make
./runGame
```

### Návod k ovládání hry lze získat pomocí příkazu:

```bash
./runGame --help
```

### Nastavení velikosti hracího pole

Velikost hracího pole lze upravit pomocí příkazové řádky:

#### Bez parametrů:

Při spuštění bez parametrů hra použije výchozí velikosti pole 40x20.

```bash
./runGame
```

#### Pouze šířka:

Nastavení šířky pole pomocí parametru -w. Výška zůstane výchozí (20).

```bash
./runGame -w 50
```

Výsledné pole bude mít velikost 50x20.

#### Pouze výška:

Nastavení výšky pole pomocí parametru -h. Šířka zůstane výchozí (40).

```bash
./runGame -h 25
```

Výsledné pole bude mít velikost 40x25.

#### Šířka i výška

Nastavení šířky i výšky současně pomocí parametrů -w a -h.

```bash
./runGame -w 60 -h 30
```

Výsledné pole bude mít velikost 60x30.

## Popis implementace

### Třída 'Point'

Třída 'Point' reprezentuje bodu v dvourozměrném prostoru, kde každý bod je definován dvěma
souřadnicemi 'x' a 'y'. Tato třída poskytuje základní funkce pro manipulaci s těmito
souřadnicemi, jako je posouvání bodu v prostoru a porovnávání bodů mezi sebou.

### Třída 'Caterpillar'

Třída 'Caterpillar' reprezentuje housenku ve hře, která se pohybuje po herním poli,
roste po sežrání potravy, a může kolidovat s hranicemi nebo se sebou samou.
Tato třída uchovává informace o aktuálním směru pohybu housenky, její délce, skóre, a počtu
životů. Housenka začíná s jedním segmentem těla, a jak se pohybuje a jí potravu, roste a
zvyšuje své skóre.

### Třída 'GameField'

Třída 'GameField' je implementována pro správu herního pole ve hře, kde hráč ovládá housenku,
která sbírá různé potravy. Tato třída se stará o umístění potravy na herní pole, detekci,
zda byla potrava snědena, a poskytuje základní informace o rozměrech herního pole.

### Třída 'InputHandler_Linux'

Třída je součástí hry, která se zaměřuje na získávání a zpracování uživatelského vstupu ve
formě klávesových stisků. V tomto případě je tato třída navržena pro prostředí Linux.
Hlavním úkolem této třídy je umožnit uživateli ovládat pohyb housenky ve hře bez čekání na
stisknutí klávesy Enter.

### Třída 'Renderer'

Třída je zodpovědná za vykreslení herního pole a zobrazení aktuálního stavu hry na konzoli.
Využívá k tomu ANSI escape sekvence pro barvy a formátování textu, což zajišťuje, že
jednotlivé herní objekty, jako je housenka, zelí, jahoda, a stěny herního pole, jsou zobrazeny
barevně odlišné a s přehledným formátováním.

### Třída 'GameLoop'

Třída obsahuje logiku pro správu a spuštění herního cyklu, včetně zpracování vstupu,
vykreslování herního pole, herní logiky (pohyb housenky, kolize, sbírání předmětů) a řízení
celkového stavu hry. Hlavní funkcí této třídy je zajištění, že hra běží v samostatných
vláknech, která se starají o různé aspekty hry.

### Třída 'Help'

Třída 'Help' obsahuje metodu printHelp, která vypisuje návod pro hru. Tento návod popisuje,
jak ovládat housenku, co je cílem hry, a jaké základní pravidla.

## Testy

Všechny klíčové metody ve třídách Caterpillar, GameField a Point jsou pečlivě otestované.
Testy lze najít ve složce 'tests' a lze spustit pomocí příkazu:

```bash
./runTests
```
