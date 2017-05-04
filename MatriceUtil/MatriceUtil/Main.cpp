#include <iostream>
#include <fstream>
#include "Matrice.h"
#include "Generator.h"

int main()
{

	int n = 1024;

	Matrice *a = new Matrice(n);
	Matrice *b = new Matrice(n);
	Matrice *c = new Matrice(n);

	Generator *gen = new Generator();
	//gen->generate(0, 3, n);
	//gen->scrieFisier("matrice1.txt");
	//gen->clear();
	//gen->generate(1, 3, n);
    //gen->scrieFisier("matrice2.txt");
	std::cout << "generate done" << std::endl;


	//a->afisareEcran();
	//a->normalInversion();
	//std::cout << a->determinant(n);
	//std::cout << std::endl;
	//a->getMinor(1, 1);
	//b->afisare("matriceNormal.txt");

	b->citire("matrice2.txt");
	//b->afisareEcran();
	//b->normalInversion();




	a->citire("matrice2.txt");
	a->afisare("matrice1.txt");
	//a->afisareEcran();
	//std::cout << std::endl;

	auto x = b->determinant();
	std::cout << x;


	

	a->tryNormal();
	a->afisare("matriceNormal.txt");
	std::cout << "Done normal";
	/*if (a->determinant(aux) != 0)
	{

		c->StrassenInversion(a);
		c->afisareEcran();
		std::cout << std::endl;
	}
	else
	{
		std::cout << "Determinantul este 0";
	}*/
	//a->afisareEcran();
	//std::cout << "---------------"<< std::endl;
	//std::cout << std::endl;
	c->matriceVida();
	c->profileMethod(&(Matrice::StrassenInversion), b);
	//c->StrassenInversion(b);
	c->afisare("matriceStrassen.txt");
	std::cout << "Done Strassen";
	//std::cout << std::endl;
	//b->afisareEcran();


	Matrice* inmultire = new Matrice(n);
	inmultire->matriceVida();
	inmultire->InmultireStrassen(a, b);
	inmultire->afisare("matrice1.txt");



	//std::cout << "Strassen:" << std::endl;
	//c->profileMethod(&(Matrice::InmultireStrassen), b, b);
	//c->afisare("matriceStrassen.txt");


	//std::cout << "Normal:" << std::endl;
	//c->profileMethod(&(Matrice::InmultireNormala), a, b);
	//c->afisare("matriceNormal.txt");
	//c->afisareEcran();




	return 0;
}