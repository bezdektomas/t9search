# IZP první projekt - t9search

>Cílem projektu je vytvořit program, který by emuloval zjednodušený algoritmus hledání kontaktů zadaných pomocí posloupnosti číslic. Vstupem programu je posloupnost číslic. Výstup programu bude obsahovat seznam kontaktů, které odpovídají zadanému číselnému filtru.
>Pro zjednodušení budeme v tomto projektu uvažovat hledání '''nepřerušené posloupnosti''' zadaných znaků/číslic v telefonním kontaktu. Nepřerušenou posloupností znaků se myslí takový podřetězec, u kterého se na každé pozici vyskytuje znak, který odpovídá jednomu ze znaků, které reprezentuje číslice na stejné pozici v zadaném řetězci. Každá číslice kromě sebe sama reprezentuje ještě následující znaky: 2 (abc), 3 (def), 4 (ghi), 5 (jkl), 6 (mno), 7 (pqrs), 8 (tuv), 9 (wxyz), 0 (+).
### <br>Kompilace
gcc -std=c99 -Wall -Wextra -Werror t9search.c -o t9search
<br>
### <br>Syntax spuštění
./t9search CISLO_T9SLOVNIK &#60;seznam.txt<br><br>
#### Příklady
./t9search 12 &#60;seznam.txt
>Petr Dvorak, 603123456<br>
>Bedrich Smetana ml., 541141120
  
<br>
  <p>./t9search &#60;seznam.txt</p>
  
>Petr Dvorak, 603123456<br>
>jana novotna, 777987654<br>
>Bedrich Smetana ml., 541141120.
