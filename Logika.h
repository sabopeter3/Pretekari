#pragma once
#include "Pretekar.h"

class Logika
{

private:
	Pretekar **zoznamPretekarov;
	int pocetPretekarov;
	int ZistiPocetPretekarov(char *nazovSuboru);

public:
	Logika();
	~Logika();
	void ZoradPodlaPriezviska(char * nazovSuboru);
	void ZoradPodlaCasu(char * nazovSuboru);
	void ZoradPodlaStartovaciehoCisla(char * nazovSuboru);
	void NacitajZoSuboru(char * nazovSuboru);
	void NacitajZKonzoly();
	void VypisNaKonzoluMuziZeny(char * nazovSuboru);
	void VypisNaKonzoluSpolu(char * nazovSuboru);
	void VypisDoSuboru(char * nazovSuboru);
};

