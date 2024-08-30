# Projekat: Filozofi za stolom

Ovaj projekat implementira problem Filozofa za stolom koristeći pthreads i semafore u C programskom jeziku.

## Opis

Program simulira problem Filozofa za stolom gde pet filozofa sedi za stolom i naizmenično misli i jede. Svaki filozof treba dve viljuške da bi pojeo, jednu sa leve i jednu sa desne strane. Program koristi semafore za upravljanje pristupom viljuškama i sprečavanje mrtvih tačaka (deadlock).

## Fajlovi

- `program.c`: Glavni C izvorni fajl koji sadrži implementaciju rešenja problema Filozofa za stolom.

## Kompilacija

Da bi se kompajlirao ovaj program, koristi sledeću komandu:

```bash
gcc -o filozofi program.c -lpthread
