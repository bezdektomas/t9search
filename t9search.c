#include <stdio.h>
#include <string.h>

int main(int argc, char const **argv)
{
    char *slovnik[10][6] = {{"+", "0", "", "", ""}, {"1", "", "", "", "", ""}, {"a", "b", "c", "2", ""}, {"d", "e", "f", "3", ""}, {"g", "h", "i", "4", ""}, {"j", "k", "l", "5", ""}, {"m", "n", "o", "6", ""}, {"p", "q", "r", "s", "7"}, {"t", "u", "v", "8", ""}, {"w", "x", "y", "z", "9"}};
    char radek[101];
    char vypis[101];
    int nalezenVysledek = 0;
    int pocetArg = argc;
    pocetArg = pocetArg;
    //Kontrala zda je zadany parametr
    if (argv[1] != NULL)
    {
        //Kontrola jestli parametr obsahuje pouze ciselne znaky, v opacnem pripade ukonceni programu
        for (int i = 0; i < (int)strlen(argv[1]); i++)
        {
            if (argv[1][i] > '9' || argv[1][i] < '0')
            {
                printf("Zadano spatne cislo.\n");
                return 0;
            }
            
        }
        
        //Cteni uzivatelskeho vstupu ze stdin

        while (fgets(radek, 101, stdin))
        {
            int delka = strlen(radek);
            //Kontrola, zda je delka radku mensi nebo rovna 100 znakum, v opacnem pripade chybova hlaska a konec programu
            if (delka <= 100)
            {
                //Zkopriovani nacteneho vstupu do nove promenne, jelikoz jsou jmena a tel cisla na jinych radcich
                //a pro naslednou praci se nam pak bude hodit kombinace obou v jednom
                for (int i = 0; i < (int)strlen(radek); i++)
                {
                    vypis[i] = radek[i];
                }

                vypis[strlen(radek) - 1] = ',';
                vypis[strlen(radek)] = ' ';

                //Nacteni dalsiho vstupu, vzdy sudy - telefonni cisla
                fgets(radek, 101, stdin);

                //Vlozeni telefonniho cisla za jmeno a carku do promenne vypis

                int pomocna = 0;
                for (int i = strlen(vypis); i < ((int)strlen(vypis) + (int)strlen(radek)); i++)
                {
                    vypis[i] = radek[pomocna];
                    pomocna++;
                }

                //Zkopirovani vypisu pomoci metody strncpy do nove prommene - bude obsahovat velka pismena
                //nasledne probehne zformatovani vypis na pouze lower case
                char unFormatedVypis[101];
                strncpy(unFormatedVypis, vypis, 100);

                for (int i = 0; vypis[i] != 0; i++)
                {
                    if (vypis[i] >= 65 && vypis[i] <= 90)
                    {
                        vypis[i] += 32;
                    }
                }

                //Algoritmus pro vyhledavani

                int porovnavanyZnak = 0;
                int nastalaZmena = 0;

                //Projizdime jednotlive kazde pismeno

                for (int k = 0; k < (int)strlen(vypis); k++)
                {
                    //Jelikoz T9 muze obsahovat na klavesu az 5 znaku, kazde pismeno porovname presne s kazdym znakem
                    for (int j = 0; j < 5; j++)
                    {
                        nastalaZmena = 0;

                        //Transformace cisla z argumentu a 2D pole na stejne datove typy
                        char pismeno = vypis[k];
                        char porovnani[2];
                        porovnani[0] = pismeno;
                        char znakHledany[2];
                        znakHledany[0] = *slovnik[argv[1][porovnavanyZnak] - '0'][j];

                        //Pokud hledany znak v T9 bude rovno znaku ze vstupu, ukonci se cyklus a hleda se na dalsim pismene
                        if (znakHledany[0] == porovnani[0])
                        {
                            j = 5;
                            porovnavanyZnak++;
                            nastalaZmena = 1;
                        }
                    }

                    //Pokud se nenasla zadna kombinace...
                    if (nastalaZmena == 0)
                    {
                        //Tak kdyz budou dva znaky za sebou stejne a jiz probehla kontrola, posuneme se v hledani o jeden
                        //znak ve vstupu zpet a opakujeme porovnani - napr. stejna cisla za sebou nebo pismena
                        if (vypis[k] == vypis[k - 1] && porovnavanyZnak > 0)
                        {
                            k--;
                        }
                        porovnavanyZnak = 0;
                    }

                    //Pokud uz je tolik shod, jako cisel v argumentu, hledani v retezci se ukonci
                    if (porovnavanyZnak == (int)strlen(argv[1]))
                    {
                        k = 100;
                    }
                }

                //Pokud vysledek hledani je uspesny, vypise se vysledek s puvodni velikosti pismen
                //a nastavi se promenna nalezenVysledek, pokud by nebylo nic nalezeno, zustane se
                //na hodnote 0 a po projeti celeho vstupu se vypise not found
                if (porovnavanyZnak != 0)
                {
                    printf("%s", unFormatedVypis);
                    nalezenVysledek = 1;
                }

                //Smazani vypisu a unFormatedVypisu pro dalsi moznou praci s nimi - aby nezustaly stare znaky
                for (int i = 0; vypis[i] != 0; i++)
                {
                    unFormatedVypis[i] = '\0';
                    vypis[i] = '\0';
                }
            }
            else
            {
                printf("Data jsou neplatna. Ukoncuji program...\n");
                return 0;
            }
        }
        if (nalezenVysledek == 0)
        {
            printf("Not found");
        }

        printf("\n");
    }
    else
    {
        //Vypsani zformatovaneho vstupu. Formatovani probiha stejnym zpusobem jako, kdyz je zadan parametr
        //Pouze neni vyuzit algoritmus.
        while (fgets(radek, 101, stdin))
        {
            int delka = strlen(radek);
            if (delka < 100)
            {
                for (int i = 0; i < (int)strlen(radek); i++)
                {
                    vypis[i] = radek[i];
                }
                vypis[strlen(radek) - 1] = ',';
                vypis[strlen(radek)] = ' ';

                fgets(radek, 101, stdin);

                int pomocna = 0;
                for (int i = strlen(vypis); i < ((int)strlen(vypis) + (int)strlen(radek)); i++)
                {
                    vypis[i] = radek[pomocna];
                    pomocna++;
                }
                printf("%s", vypis);

                for (int i = 0; vypis[i] != 0; i++)
                {
                    vypis[i] = '\0';
                }
            }
            else
            {
                printf("Data jsou neplatná.\n");
                return 0;
            }
        }
        printf("\n");
    }

    return 0;
}
