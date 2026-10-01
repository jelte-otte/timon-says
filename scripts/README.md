# Header synchroniseren

Open een `.cpp`-bestand in VS Code en druk op **Ctrl+Shift+B**. De taak maakt
een gelijknamige `.h` aan of werkt de sectie tussen
`// BEGIN GENERATED DECLARATIONS` en `// END GENERATED DECLARATIONS` bij.

Vanaf de terminal kan hetzelfde met:

```sh
python3 scripts/sync_header.py src/Config/Config.cpp
```

Het script herkent eenvoudige globale variabelen, vrije functies en enums.
Een enum uit de `.cpp` wordt naar de `.h` verplaatst, zodat de waarden ook
vanuit andere bestanden bruikbaar zijn. Pas de enum daarna in de header aan.
Structs, classes, templates en bestaande headers zonder markeringen blijven
handwerk; een bestaande
header zonder markeringen wordt niet overschreven.
