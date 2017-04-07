#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

class Matrice
{

public:

	Matrice(int n);
	~Matrice();
	void citire(std::string numeFisier);
	void matriceVida();
	void afisare(std::string numeFisier);
	void afisareEcran();
	void InmultireNormala(Matrice *firstMatrix, Matrice *secondMatrix);
	static Matrice* Scadere(Matrice *firstMatrix, Matrice *secondMatrix);
	static Matrice* Adunare(Matrice *firstMatrix, Matrice *secondMatrix);
	void Split(Matrice *destination, int destI, int destJ);
	void Join(Matrice *destination, int destI, int destJ);
	void InmultireStrassen(Matrice *firstMatrix, Matrice *secondMatrix);
	void profileMethod(void(Matrice::*functie)(Matrice*, Matrice*), Matrice *firstMatrix, Matrice *secondMatrix);

private:
	short **matrice;
	int n;


};


#endif