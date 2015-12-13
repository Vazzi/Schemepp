# Schemepp
Implementace Scheme v C++.

* Stránský Vojtěch(stranvo1)
* Vlasák Jakub (vlasaj10)

Interpretujeme bytecode Scheme jazyka vytvořeného pomocí Bob compileru.

## Poznámka

Tento compiler neumí pracovat s řetězci a tak jsme zvolili program, jenž řetězce nepoužívá. Zároveň nemůžeme díky tomu implementovat klasickou metodu práce se soubory a tak jsme zvolili přístup takový, že při spuštění VM specifikujeme vstupní a výstupní soubor (oba jako volitelné parametry) a tyto soubory následně program používá (funkce: read, fileNextLine, write a newline). Pokud není specifikovaný vstupní soubor a program i tak zavolá některou ze čtecích funkcí, vrátí se error. Pokud není specifikován výstupní soubor je výstup zobrazen v konzoli.

## Struktura

* compiler ... kompilátor Scheme
* bin ... zkompilovaný Schemepp (vytvoří se po kompilaci)
* scheme ... program v jazyce Scheme
    * / compile.py ... script jenž spustí kompilaci vybraného souboru
    * / problem.scm ... implementovaný problém v Scheme
    * / input.dat ... vstupní data pro daný problém
* src ... zdrojové kódy Schemepp
* CMakeLists.txt ... specifikace pro cmake
* Readme.md ... readme

## Kompilace Schemepp

Pro kompilaci Schemepp používáme program cmake.

1. cmake .
2. make

Spustitelný soubor: bin/Schemepp

## Spuštění programu ve Schemepp

Ve složce bin:

```sh
$ ./Schemepp <bytecode.bobc> <vystupni_soubor> -i <vstupni_soubor>
```

<vstupni_soubor> a <vystupni_soubor> ... volitelné parametry

## Kompilace programu do bytecode

Ve složce scheme:

```sh
$ ./python3 compile.py problem.scm
```

Vytvoří .bobc soubor jenž zpracuje VM

## Spuštění příkladu

1. Vygenerovat .bobc soubor pomocí kompilátoru (viz předchozí bod).
2. Zkopírovat vygenerovaný problem.bobc a input.dat soubor do složky bin
3. Spustit: Schemepp problem.bobc -i input.dat
4. VM vypíše do konzole výsledek
