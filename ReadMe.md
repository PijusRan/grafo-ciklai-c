`10. Patikrinti, ar orientuotame grafe yra ciklų. Ciklas yra iš grafo briaunų sudarytas kelias, kuris prasideda ir baigiasi toje pačioje viršūnėje.`

## Bendravimas ir Bendradarbiavimas

Daug aptarta su kolegomis dėl sprendimo būdo.

## Programos naudojimas

### Makefile

Makefile sukuria test.exe programos naudojimui. Reikalinga biblioteka (angl. package) `make`

```
$ make
```

### Go.cmd

Paleidžia programą (Windows aplinkoje)

```
$ ./Go.cmd
```

### Paleistis sukompiliavus

```
$ main.exe <failas.cfg>
```

Parametrai:

 - `<failas>` - grafo failas (`.cfg` plėtiniu)
 - `-h` - pagalbos žinutei

### Įvestis

Įvestis gaunama iš pateikto `.cfg` failo

`.cfg` rašymo tvarka:

 - Pirma eilutė - taškų skaičius `n` ir jungčių skaičius `c`
 - Likusios `c` eilutės - jungtis iš `a` į `b` 

`.cfg` pavyzdys:

```
n c
a b
a b
a b
... (c eilučių)
```
