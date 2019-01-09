#include "Pretekar.h"


Pretekar::Pretekar(char *paPriezvisko, char *paMeno, char paPohlavie, unsigned int paStartovacieCislo, int paCas) :
	priezvisko(paPriezvisko),
	meno(paMeno),
	pohlavie(paPohlavie),
	startovacieCislo(paStartovacieCislo),
	cas(paCas)
{
}


Pretekar::~Pretekar()
{
	delete meno;
	delete priezvisko;
}
