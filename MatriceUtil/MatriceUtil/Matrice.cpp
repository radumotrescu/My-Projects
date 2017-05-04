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
	matrice = new double*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new double[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			fin >> matrice[i][j];
		}
}

void Matrice::matriceVida()
{
	matrice = new double*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new double[n];
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
			double sum = 0;
			for (int k = 0; k < n; k++)
				sum += firstMatrix->matrice[i][k] * secondMatrix->matrice[k][j];
			matrice[i][j] = sum;
		}

}

Matrice* Matrice::Scadere(Matrice *firstMatrix, Matrice *secondMatrix)
{
	Matrice *result = new Matrice(firstMatrix->n);

	int n = firstMatrix->n;

	result->matrice = new double*[n];
	for (int i = 0; i < n; i++)
		result->matrice[i] = new double[n];

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
	result->matrice = new double*[n];

	for (int i = 0; i < n; i++)
		result->matrice[i] = new double[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			result->matrice[i][j] = firstMatrix->matrice[i][j] + secondMatrix->matrice[i][j];
		}
	return result;
}

void Matrice::MinusMatrix()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			matrice[i][j] = -matrice[i][j];
		}

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
	matrice = new double*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new double[n];

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


void Matrice::StrassenInversion(Matrice * matrix)
{


	n = matrix->n;
	matrice = new double*[n];
	for (int i = 0; i < n; i++)
		matrice[i] = new double[n];

	if (n == 1)
	{
		matrice[0][0] = 1 / matrix->matrice[0][0];
	}
	//if (n <= 32)
	//{
	//	matrix->normalInversion();
	//}
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

		matrix->Split(A11, 0, 0);
		//A11->afisareEcran();
		matrix->Split(A12, 0, n / 2);
		//A12->afisareEcran();
		matrix->Split(A21, n / 2, 0);
		//A21->afisareEcran();
		matrix->Split(A22, n / 2, n / 2);
		//A22->afisareEcran();


		Matrice *R1 = new Matrice(n / 2);
		R1->matriceVida();
		Matrice *R2 = new Matrice(n / 2);
		R2->matriceVida();
		Matrice *R3 = new Matrice(n / 2);
		R3->matriceVida();
		Matrice *R4 = new Matrice(n / 2);
		R4->matriceVida();
		Matrice *R5 = new Matrice(n / 2);
		R5->matriceVida();
		Matrice *R6 = new Matrice(n / 2);
		R6->matriceVida();
		Matrice *S = new Matrice(n / 2);
		S->matriceVida();

		R1->StrassenInversion(A11);


		R2->InmultireStrassen(A21, R1);

		R3->InmultireStrassen(R1, A12);


		R4->InmultireStrassen(A21, R3);


		S = Scadere(A22, R4);


		R5->StrassenInversion(S);


		Matrice *C1 = new Matrice(n / 2);
		C1->matriceVida();

		Matrice *C2 = new Matrice(n / 2);
		C2->matriceVida();

		Matrice *C3 = new Matrice(n / 2);
		C3->matriceVida();
		Matrice *C4 = new Matrice(n / 2);
		C4->matriceVida();


		C4 = R5;

		C2->InmultireStrassen(R3, R5);
		C2->MinusMatrix();

		C3->InmultireStrassen(R5, R2);
		C3->MinusMatrix();

		R6->InmultireStrassen(C2, R2);

		C1 = Scadere(R1, R6);

		//C1->afisareEcran();
		//C2->afisareEcran();	
		//C3->afisareEcran();
		//C4->afisareEcran();
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

void Matrice::profileMethod(void(Matrice::* functie)(Matrice *), Matrice * Matrix)
{
	auto start = std::chrono::high_resolution_clock::now();

	(this->*functie)(Matrix);

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	std::cout << "This took " << duration.count() << " milliseconds " << std::endl;
}

void Matrice::rotireMatrice()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double aux = matrice[i][j];
			matrice[i][j] = matrice[j][i];
			matrice[j][i] = aux;
		}
	}
}

void Matrice::swapRow(Matrice *matrix, int row1, int row2)
{
	for (int i = 0; i < n; i++)
	{
		int aux = matrix->matrice[row1][i];
		matrix->matrice[row1][i] = matrix->matrice[row2][i];
		matrix->matrice[row2][i] = aux;
	}
}

void Matrice::swapRow(int **matrix, int row1, int row2)
{
	for (int i = 0; i < n; i++)
	{
		int aux = matrix[row1][i];
		matrix[row1][i] = matrix[row2][i];
		matrix[row2][i] = aux;
	}
}



long long int Matrice::determinant()
{

	Matrice* copyMatrix = new Matrice(n);
	copyMatrix->matriceVida();


	int **copy = new int*[n];
	for (int i = 0; i < n; i++)
	{
		copy[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			copy[i][j] = (int)matrice[i][j];
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		std::cout << copy[i][j] << " ";
	//	std::cout << std::endl;
	//}

	long long int result = 1;
	for (int j = 0; j < n; j++)
	{
		bool found = false;
		for (int i = j; i < n; i++)
		{
			if (copy[i][j] != 0)
			{
				if (i != j)
				{
					result *= -1;
					swapRow(copy, i, j);
				}
				found = true;
				break;
			}
		}
		if (found == false)
			return 0;
		for (int i = j + 1; i < n; i++)
		{
			while (true)
			{
				int del = copy[i][j] / copy[j][j];

				for (int k = j; k < n; k++)
				{
					int x = del*copy[j][k];
					copy[i][k] -= x;
				}
				if (copy[i][j] == 0)
				{
					break;
				}
				else
				{
					result *= -1;
					swapRow(copy, i, j);
				}
			}
		}
		//copy->afisareEcran();
		//std::cout << "OMG" << std::endl;
		//for (int i = 0; i < n; i++)
		//{
		//	for (int j = 0; j < n; j++)
		//		std::cout << copy[i][j] << " ";
		//	std::cout << std::endl;

		//}
		//std::cout << "OMG" << std::endl;
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		std::cout << copy[i][j] << " ";
	//	std::cout << std::endl;

	//}
	//copy->afisareEcran();
	//std::cout << "OMG" << std::endl;
	for (int i = 0; i < n; i++)
	{
		result *= copy[i][i];
	}
	//if (result < 0)
	//	return -result;
	delete[] copy;
	return result;

}

void Matrice::getTransposeMatrix()
{

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			double aux = matrice[i][j];
			matrice[i][j] = matrice[j][i];
			matrice[j][i] = aux;
		}
	}

}

Matrice* Matrice::getMinor(int row, int col)
{

	Matrice* minor = new Matrice(n - 1);
	minor->matriceVida();
	int k, l;
	k = -1;
	l = 0;
	for (int i = 0; i < n; i++)
	{
		l = 0;
		if (row != i)
		{
			k++;
			for (int j = 0; j < n; j++)
			{
				if (j != col)
				{
					minor->matrice[k][l++] = matrice[i][j];

				}

			}
		}

	}

	//for (int i = 0; i < n - 1; i++)
	//{
	//	for (int j = 0; j < n - 1; j++)
	//		std::cout << minor[i][j] << " ";
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;

	return minor;
}

//double Matrice::determinant2(double d)
//{
//	
//		int c, subi, i, j, subj;
//		double submat[10][10];
//		if (n == 2)
//		{
//			return((mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]));
//		}
//		else
//		{
//			for (c = 0; c < n; c++)
//			{
//				subi = 0;
//				for (i = 1; i < n; i++)
//				{
//					subj = 0;
//					for (j = 0; j < n; j++)
//					{
//						if (j == c)
//						{
//							continue;
//						}
//						submat[subi][subj] = mat[i][j];
//						subj++;
//					}
//					subi++;
//				}
//				d = d + (pow(-1, c) * mat[0][c] * det(n - 1, submat));
//			}
//		}
//		return d;
//	
//}




void Matrice::normalInversion()
{

	auto start = std::chrono::high_resolution_clock::now();

	

	
	int det = determinant();
	std::cout << det << std::endl;


	Matrice* inverted = new Matrice(n);
	inverted->matriceVida();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			Matrice* minor = new Matrice(n - 1);
			minor->matriceVida();
			minor = getMinor(i, j);
			//minor->afisareEcran();
			//this->afisareEcran();
			long long int var = minor->determinant();
			//std::cout << var << " " <<i << " " << j << std::endl;
			//std::cout << std::endl;
			inverted->matrice[i][j] = var;
			minor->~Matrice();
		}
	}
	//afisareEcran();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			matrice[i][j] = inverted->matrice[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if ((i + j) % 2 == 1)
			{
				matrice[i][j] = -matrice[i][j];
			}
		}
	}

	getTransposeMatrix();

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrice[i][j] = matrice[i][j] / det;
		}
	}

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	std::cout << "This took " << duration.count() << " milliseconds " << std::endl;

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < n; j++)
	//		std::cout << matrice[i][j] << " ";
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//std::cout << det;

}

void Matrice::tryNormal()
{
	auto start = std::chrono::high_resolution_clock::now();

	double** matrix = new double*[n];
	for (int i = 0; i < n; i++)
	{
		matrix[i] = new double[2 * n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			matrix[i][j] = matrice[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
		{
			if (i == (j - n))
				matrix[i][j] = 1.0;
			else
				matrix[i][j] = 0.0;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				double ratio = matrix[j][i] / matrix[i][i];
				for (int k = 0; k < 2 * n; k++)
				{
					matrix[j][k] -= ratio * matrix[i][k];
				}
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		double a = matrix[i][i];
		for (int j = 0; j < 2 * n; j++)
		{
			matrix[i][j] /= a;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = n; j < 2 * n; j++)
			matrice[i][j-n] = matrix[i][j];
		
	}

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	std::cout << "This took " << duration.count() << " milliseconds " << std::endl;
}
