#include "Matrice.h"
#include <fstream>


Matrice::Matrice(int n)
{
	this->n = n;
}

Matrice::~Matrice()
{

	delete[] matrice;
}

void Matrice::citire(std::string numeFisier)
{
	std::ifstream fin(numeFisier);
	matrice = new short*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new short[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> matrice[i][j];
		}
}

void Matrice::matriceVida()
{
	matrice = new short*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new short[n];
}

void Matrice::afisare(std::string numeFisier)
{
	std::ofstream fout(numeFisier);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			fout << this->matrice[i][j] << " ";
		fout << std::endl;
	}
	fout.close();


}

void Matrice::afisareEcran()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << this->matrice[i][j] << " ";
		std::cout << std::endl;
	}
}

void Matrice::InmultireNormala(Matrice *firstMatrix, Matrice *secondMatrix)
{

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int sum = 0;
			for (int k = 0; k < n; k++)
				sum += firstMatrix->matrice[i][k] * secondMatrix->matrice[k][j];
			matrice[i][j] = sum;
		}

}

Matrice* Matrice::Scadere(Matrice *firstMatrix, Matrice *secondMatrix)
{
	Matrice *result = new Matrice(firstMatrix->n);

	int n = firstMatrix->n;

	result->matrice = new short*[n];
	for (int i = 0; i < n; i++)
		result->matrice[i] = new short[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			result->matrice[i][j] = firstMatrix->matrice[i][j] - secondMatrix->matrice[i][j];
		}
	return result;
}

Matrice* Matrice::Adunare(Matrice *firstMatrix, Matrice *secondMatrix)
{
	Matrice *result = new Matrice(firstMatrix->n);

	int n = firstMatrix->n;
	result->matrice = new short*[n];

	for (int i = 0; i < n; i++)
		result->matrice[i] = new short[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			result->matrice[i][j] = firstMatrix->matrice[i][j] + secondMatrix->matrice[i][j];
		}
	return result;
}

void Matrice::Split(Matrice *child, int destI, int destJ)
{
	for (int i1 = 0, i2 = destI; i1 < child->n; i1++, i2++)
		for (int j1 = 0, j2 = destJ; j1 < child->n; j1++, j2++)
		{
			child->matrice[i1][j1] = matrice[i2][j2];
		}
}

void Matrice::Join(Matrice  *child, int destI, int destJ)
{
	for (int i1 = 0, i2 = destI; i1 < child->n; i1++, i2++)
		for (int j1 = 0, j2 = destJ; j1 < child->n; j1++, j2++)
		{
			matrice[i2][j2] = child->matrice[i1][j1];
		}
}

void Matrice::InmultireStrassen(Matrice * firstMatrix, Matrice * secondMatrix)
{
	n = firstMatrix->n;
	matrice = new short*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new short[n];

	if (n == 1)
	{
		matrice[0][0] = firstMatrix->matrice[0][0] * secondMatrix->matrice[0][0];

		//std::cout << firstMatrix->matrice[0][0] << " " << secondMatrix->matrice[0][0] << " " << matrice[0][0] <<std:: endl;
	}
	if (n <= 128)
	{
		InmultireNormala(firstMatrix, secondMatrix);
	}
	else
	{
		Matrice *A11 = new Matrice(n / 2);
		A11->matriceVida();
		Matrice *A12 = new Matrice(n / 2);
		A12->matriceVida();
		Matrice *A21 = new Matrice(n / 2);
		A21->matriceVida();
		Matrice *A22 = new Matrice(n / 2);
		A22->matriceVida();
		Matrice *B11 = new Matrice(n / 2);
		B11->matriceVida();
		Matrice *B12 = new Matrice(n / 2);
		B12->matriceVida();
		Matrice *B21 = new Matrice(n / 2);
		B21->matriceVida();
		Matrice *B22 = new Matrice(n / 2);
		B22->matriceVida();

		firstMatrix->Split(A11, 0, 0);
		firstMatrix->Split(A12, 0, n / 2);
		firstMatrix->Split(A21, n / 2, 0);
		firstMatrix->Split(A22, n / 2, n / 2);
		secondMatrix->Split(B11, 0, 0);
		secondMatrix->Split(B12, 0, n / 2);
		secondMatrix->Split(B21, n / 2, 0);
		secondMatrix->Split(B22, n / 2, n / 2);


		/**
		M1 = (A11 + A22)(B11 + B22)
		M2 = (A21 + A22) B11
		M3 = A11 (B12 - B22)
		M4 = A22 (B21 - B11)
		M5 = (A11 + A12) B22
		M6 = (A21 - A11) (B11 + B12)
		M7 = (A12 - A22) (B21 + B22)
		**/



		Matrice *M1 = new Matrice(n / 2);
		M1->matriceVida();
		Matrice *M2 = new Matrice(n / 2);
		M2->matriceVida();
		Matrice *M3 = new Matrice(n / 2);
		M3->matriceVida();
		Matrice *M4 = new Matrice(n / 2);
		M4->matriceVida();
		Matrice *M5 = new Matrice(n / 2);
		M5->matriceVida();
		Matrice *M6 = new Matrice(n / 2);
		M6->matriceVida();
		Matrice *M7 = new Matrice(n / 2);
		M7->matriceVida();

		M1->InmultireStrassen(Adunare(A11, A22), Adunare(B11, B22));
		M2->InmultireStrassen(Adunare(A21, A22), B11);
		M3->InmultireStrassen(A11, Scadere(B12, B22));
		M4->InmultireStrassen(A22, Scadere(B21, B11));
		M5->InmultireStrassen(Adunare(A11, A12), B22);
		M6->InmultireStrassen(Scadere(A21, A11), Adunare(B11, B12));
		M7->InmultireStrassen(Scadere(A12, A22), Adunare(B21, B22));


		/**
		C11 = M1 + M4 - M5 + M7
		C12 = M3 + M5
		C21 = M2 + M4
		C22 = M1 - M2 + M3 + M6
		**/

		Matrice *C1 = new Matrice(n / 2);
		C1->matriceVida();
		Matrice *C2 = new Matrice(n / 2);
		C2->matriceVida();
		Matrice *C3 = new Matrice(n / 2);
		C3->matriceVida();
		Matrice *C4 = new Matrice(n / 2);
		C4->matriceVida();

		C1 = Adunare(Scadere(Adunare(M1, M4), M5), M7);
		C2 = Adunare(M3, M5);
		C3 = Adunare(M2, M4);
		C4 = Adunare(Scadere(Adunare(M1, M3), M2), M6);

		Join(C1, 0, 0);
		Join(C2, 0, n / 2);
		Join(C3, n / 2, 0);
		Join(C4, n / 2, n / 2);

	}

}

void Matrice::profileMethod(void(Matrice::* functie)(Matrice *, Matrice *), Matrice * firstMatrix, Matrice * secondMatrix)
{

	auto start = std::chrono::high_resolution_clock::now();

	(this->*functie)(firstMatrix, secondMatrix);

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	std::cout << "This took " << duration.count() << " milliseconds " << std::endl;
}


