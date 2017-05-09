#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Generator.h"

int main()
{

	int n = 512;

	Matrice *a = new Matrice(n);
	Matrice *b = new Matrice(n);
	Matrice *c = new Matrice(n);

	Generator *gen = new Generator();
	gen->generate(1, 3, n);
	gen->scrieFisier("matrice1.txt");
	//gen->clear();
	//gen->generate(1, 3, n);
	//gen->scrieFisier("matrice2.txt");
	std::cout << "Number generating done" << std::endl;


	a->citire("matrice1.txt");
	b->citire("matrice1.txt");
	c->matriceVida();

	std::cout << "Inversare naiva: " << std::endl;
	c->profileMethod(&(Matrice::normalInversion), b);
	c->afisare("matriceNormal.txt");

	std::cout << "Inversare Strassen: ";
	c->profileMethod(&(Matrice::StrassenInversion), b);
	c->afisare("matriceStrassen.txt");


	//std::cout << "Inmultire naiva: " << std::endl;
	//c->profileMethod(&(Matrice::InmultireNormala), a, b);
	//c->afisare("matriceNormal.txt");



	//std::cout << "Inmultire Strassen: " << std::endl;
	//c->profileMethod(&(Matrice::InmultireStrassen), a, b);
	//c->afisare("matriceStrassen.txt");

	return 0;
}