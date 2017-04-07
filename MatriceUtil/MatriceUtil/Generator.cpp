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
		int numar = rand() % max + min;
		listaNumere.push_back(numar);
	}
	
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
