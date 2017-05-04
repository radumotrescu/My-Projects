#pragma once
#include <cstdlib>
#include <vector>
#include <time.h>
#include <string>
#include <fstream>

class Generator
{
public:
	Generator();
	~Generator();
	void generate(int min, int max, int nr);
	void clear();
	void scrieFisier(std::string numeFisier);

private:
	std::vector<double> listaNumere;
};

