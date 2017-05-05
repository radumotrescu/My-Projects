#ifndef _BOOK_H_
#define _BOOK_H_
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

class Matrice {

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
	void MinusMatrix();
	void Split(Matrice *destination, int destI, int destJ);
	void Join(Matrice *destination, int destI, int destJ);
	void InmultireStrassen(Matrice *firstMatrix, Matrice *secondMatrix);
	void profileMethod(void(Matrice::*functie)(Matrice*, Matrice*), Matrice *firstMatrix, Matrice *secondMatrix);
	void profileMethod(void(Matrice::*functie)(Matrice*), Matrice *Matrix);
	void rotireMatrice();


	long long int determinant();
	void swapRow(Matrice *matrix, int row1, int row2);


	void normalInversion(Matrice* matrix);

	void getTransposeMatrix();
	Matrice* getMinor(int row, int col);
	void Matrice::swapRow(int **matrix, int row1, int row2);


	void StrassenInversion(Matrice *Matrix);

private:
	double **matrice;

	// the dimension NxN of the matrix
	int n;


};


#endif