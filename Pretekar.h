#pragma once

class Pretekar
{

private:
	char *priezvisko;
	char *meno;
	char pohlavie;
	unsigned int startovacieCislo;
	int cas;

public:
	Pretekar(char *paPriezvisko, char *paMeno, char paPohlavie, unsigned int paStartovacieCislo, int paCas);
	~Pretekar();
	char *GetPriezvisko() { return priezvisko; };
	char *GetMeno() { return meno; };
	char GetPohlavie() { return pohlavie; };
	unsigned int GetStartovacieCislo() { return startovacieCislo; };
	int GetCas() { return cas; };
};

