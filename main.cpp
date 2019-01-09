#include "Logika.h"

/*
spoluautor - Lukas Durec
*/

int main() {
	Logika logic;
	logic.NacitajZoSuboru("Pretekari1.txt");
	//logic.NacitajZKonzoly();
	//logic.ZoradPodlaCasu("Pretekari1.txt");
	//logic.ZoradPodlaStartovaciehoCisla("Pretekari1.txt");
	logic.ZoradPodlaPriezviska("Pretekari1.txt");
	//logic.VypisNaKonzoluMuziZeny("Pretekari1.txt");
	logic.VypisNaKonzoluSpolu("Pretekari1.txt");
	logic.VypisDoSuboru("Vysledky.txt");
}