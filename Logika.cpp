#include <iostream>
#include <time.h>
#include "stdio.h"
#include "Logika.h"

using namespace std;

int pocet = 0;

Logika::Logika()
{
}


Logika::~Logika()
{
	delete[] zoznamPretekarov;
}


int Logika::ZistiPocetPretekarov(char * nazovSuboru)
{
	if (nazovSuboru && *nazovSuboru)
	{
		FILE *subor = fopen(nazovSuboru, "r");
		if (subor)
		{
			int vstup = 0;
			char znak = ' ';
			while (vstup >= 0)
			{
				vstup = fscanf(subor, "%c", &znak);
				if (znak == '\n') pocet++;
			}
			fclose(subor);
			pocet++;
		}
	}
	return pocet;
}

void Logika::NacitajZoSuboru(char * nazovSuboru)
{
	srand(time(NULL));
	if (nazovSuboru && *nazovSuboru)
	{
		int pocet(ZistiPocetPretekarov(nazovSuboru));
		FILE *subor = fopen(nazovSuboru, "r");
		if (subor)
		{
			if (pocet > 0)
			{
				unsigned int startovacieCislo = 1;
				zoznamPretekarov = new (nothrow) Pretekar*[pocet];
				for (int i = 0; i < pocet; i++)
				{
					char *meno = new (nothrow) char[20];
					char *priezvisko = new (nothrow) char[20];
					char pohlavie;
					fscanf(subor, "%s ", priezvisko);
					fscanf(subor, "%s ", meno);
					fscanf(subor, "%c ", &pohlavie);

					int rozsah = 9095 - 7140 + 1; //cas v rozsahu 1:59:00 - 2:31:35 prevedene na sekundy
					int cas = rand() % rozsah + 7140; //generovanie nahodnych casov

					Pretekar *pretekar = new Pretekar(priezvisko, meno, pohlavie, startovacieCislo, cas);
					zoznamPretekarov[i] = pretekar;
					startovacieCislo++;
				}
			}
			fclose(subor);
		}
	}
}

void Logika::NacitajZKonzoly()
{
	srand(time(NULL));
	printf("Zadaj pocet pretekarov :\n");
	cin >> pocet;
	if (pocet > 0)
	{
		unsigned int startovacieCislo = 1;
		zoznamPretekarov = new (nothrow) Pretekar*[pocet];
		for (int i = 0; i < pocet; i++)
		{
			char *meno = new (nothrow) char[20];
			char *priezvisko = new (nothrow) char[20];
			char *pohlavie = new (nothrow) char[2];
			printf("Zadaj priezvisko :\n");
			cin >> priezvisko;
			printf("Zadaj meno :\n");
			cin >> meno;
			printf("Zadaj pohlavie (M/F) :\n");
			cin >> pohlavie;

			int rozsah = 9095 - 7140 + 1; //cas v rozsahu 1:59:00 - 2:31:35 prevedene na sekundy
			int cas = rand() % rozsah + 7140; //generovanie nahodnych casov

			Pretekar *pretekar = new Pretekar(priezvisko, meno, pohlavie[0], startovacieCislo, cas);
			zoznamPretekarov[i] = pretekar;
			startovacieCislo++;
		}
	}
}

void Logika::ZoradPodlaPriezviska(char * nazovSuboru)
{
	printf("**************************************************\nVysledky podla priezviska (abecedne)\n**************************************************\n");

	for (int i = 0; i < pocet; i++)
	{
		for (int j = 0; j < pocet - 1; j++)
		{
			if (strcmp(zoznamPretekarov[j]->GetPriezvisko(), zoznamPretekarov[j + 1]->GetPriezvisko()) > 0)
			{
				Pretekar *p(zoznamPretekarov[j]);
				zoznamPretekarov[j] = zoznamPretekarov[j + 1];
				zoznamPretekarov[j + 1] = p;
			}
		}
	}
}

void Logika::ZoradPodlaStartovaciehoCisla(char * nazovSuboru)
{
	printf("**************************************************\nVysledky podla startovacieho cisla\n**************************************************\n");

	for (int i = 0; i < pocet; i++)
	{
		for (int j = 0; j < pocet - 1; j++)
		{
			if (zoznamPretekarov[j]->GetStartovacieCislo() > zoznamPretekarov[j + 1]->GetStartovacieCislo())
			{
				Pretekar *p(zoznamPretekarov[j]);
				zoznamPretekarov[j] = zoznamPretekarov[j + 1];
				zoznamPretekarov[j + 1] = p;
			}
		}
	}
}

void Logika::ZoradPodlaCasu(char * nazovSuboru)
{
	printf("**************************************************\nVysledky podla casu\n**************************************************\n");

	for (int i = 0; i < pocet; i++)
	{
		for (int j = 0; j < pocet - 1; j++)
		{
			if (zoznamPretekarov[j]->GetCas() > zoznamPretekarov[j + 1]->GetCas())
			{
				Pretekar *p(zoznamPretekarov[j]);
				zoznamPretekarov[j] = zoznamPretekarov[j + 1];
				zoznamPretekarov[j + 1] = p;
			}
		}
	}
}

void Logika::VypisNaKonzoluSpolu(char * nazovSuboru)
{
	int poradie = 1;

	for (int i = 0; i < pocet; i++)
	{
		int cislo = zoznamPretekarov[i]->GetStartovacieCislo();
		char pohlavie = zoznamPretekarov[i]->GetPohlavie();
		int cas = zoznamPretekarov[i]->GetCas();

		int hodiny = cas / 3600;
		cas = cas % 3600;
		int minuty = cas / 60;
		cas = cas % 60;
		printf("%2d. (%2d) %-15s %-15s %02d:%02d:%02d\n",
			poradie,
			cislo,
			zoznamPretekarov[i]->GetMeno(),
			zoznamPretekarov[i]->GetPriezvisko(),
			hodiny,
			minuty,
			cas
			);
		poradie++;
	}
	printf("**************************************************\n");
}

void Logika::VypisNaKonzoluMuziZeny(char * nazovSuboru)
{
	printf("**************************************************\nMUZI\n**************************************************\n");

	int poradie = 1;

	for (int i = 0; i < pocet; i++)
	{
		int cislo = zoznamPretekarov[i]->GetStartovacieCislo();
		char pohlavie = zoznamPretekarov[i]->GetPohlavie();
		int cas = zoznamPretekarov[i]->GetCas();

		if (pohlavie != 'M')
		{
			continue;
		}

		int hodiny = cas / 3600;
		cas = cas % 3600;
		int minuty = cas / 60;
		cas = cas % 60;
		printf("%2d. (%2d) %-15s %-15s %02d:%02d:%02d\n",
			poradie,
			cislo,
			zoznamPretekarov[i]->GetMeno(),
			zoznamPretekarov[i]->GetPriezvisko(),
			hodiny,
			minuty,
			cas
			);
		poradie++;
	}

	printf("**************************************************\nZENY\n**************************************************\n");

	poradie = 1;
	for (int i = 0; i < pocet; i++)
	{
		int cislo = zoznamPretekarov[i]->GetStartovacieCislo();
		char pohlavie = zoznamPretekarov[i]->GetPohlavie();
		int cas = zoznamPretekarov[i]->GetCas();

		if (pohlavie != 'F')
		{
			continue;
		}

		int hodiny = cas / 3600;
		cas = cas % 3600;
		int minuty = cas / 60;
		cas = cas % 60;
		printf("%2d. (%2d) %-15s %-15s %02d:%02d:%02d\n",
			poradie,
			cislo,
			zoznamPretekarov[i]->GetMeno(),
			zoznamPretekarov[i]->GetPriezvisko(),
			hodiny,
			minuty,
			cas
			);
		poradie++;
	}

	printf("**************************************************\n");
}

void Logika::VypisDoSuboru(char * nazovSuboru)
{
	if (nazovSuboru && *nazovSuboru)
	{
		FILE *subor = fopen(nazovSuboru, "w");
		if (subor)
		{
			for (int i = 0; i < pocet; i++)
			{
				fprintf(subor, "%u.: %s %s \n", zoznamPretekarov[i]->GetStartovacieCislo(), zoznamPretekarov[i]->GetPriezvisko(), zoznamPretekarov[i]->GetMeno());
			}
			fclose(subor);
		}
	}
}
