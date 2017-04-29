#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Generator.h"

int main()
{

	int n = 10;

	Matrice *a = new Matrice(n);
	Matrice *b = new Matrice(n);
	Matrice *c = new Matrice(n);

	Generator *gen = new Generator();
	gen->generate(0, 5, 50,2);
	gen->scrieFisier("matrice1.txt");
	//gen->clear();
	//gen->generate(0, 50, n);
	//gen->scrieFisier("matrice2.txt");
	//std::cout << "generate done" << std::endl;

	a->citire("matrice1.txt");
	b->citire("matrice2.txt");
	c->matriceVida();

	a->covariance();

	//std::cout << "Strassen:" << std::endl;
	//c->profileMethod(&(Matrice::InmultireStrassen), a, b);
	//c->afisare("matriceStrassen.txt");


	//std::cout << "Normal:" << std::endl;
	//c->profileMethod(&(Matrice::InmultireNormala), a, b);
	//c->afisare("matriceNormal.txt");
	//c->afisareEcran();




	return 0;
}