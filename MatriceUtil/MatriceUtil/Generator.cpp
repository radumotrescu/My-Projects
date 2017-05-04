#include "Generator.h"



Generator::Generator()
{
	std::srand(time(NULL));
}


Generator::~Generator()
{

}

void Generator::generate(int min, int max, int nr)
{
	int n = nr*nr;

	for (auto i = 0; i < n; i++)
	{
		//double numar = (double)rand() / RAND_MAX;
		//numar = min + numar*(max - min);
		int numar = rand() % max + min;
		listaNumere.push_back(numar);
	}

	//for (int i = 0; i < n; i++)
	//	listaNumere.push_back(i);
	
}

void Generator::clear()
{
	listaNumere.clear();
}



void Generator::scrieFisier(std::string numeFisier)
{
	std::ofstream fout(numeFisier);
	for (auto numar : listaNumere)
	{
		fout << numar << std::endl;
	}
	fout.close();
}
