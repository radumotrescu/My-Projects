#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"
#include <fstream>
#include <regex>
#include <string>
#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

Book::Book()
{
}


Book::~Book()
{
}

void Book::citire()
{

	ifstream fin("carte.txt");
	string line;
	while (getline(fin, line))
	{
		carteIntreaga += '\n';
		carteIntreaga += line;
	}

}

void Book::afisare()
{
	cout << carteIntreaga;
}

void Book::creareVector()
{

	/*regex rgx("[\-:,.;(\"\\s]+");
	sregex_token_iterator iter(carteIntreaga.begin(),
		carteIntreaga.end(),
		rgx,
		-1);
	sregex_token_iterator end;
	for (; iter != end; ++iter)
		vector.push_back(*iter);*/


	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";
	char *token;

	token = strtok(&aux[0], separatori);
	while (token != NULL)
	{
		string toPush = token;
		vector.push_back(toPush);
		token = strtok(NULL, separatori);
	}



	cout << "Creare vector de un cuvant" << endl;
	/*ofstream fout("cuvinte.txt");
	for each (auto s in vector)
	{
		fout << s << endl;
	}
	fout.close();*/




}


void Book::creareMap()
{
	/*regex rgx("[\-:,.;(\"\\s]+");
	sregex_token_iterator iter(carteIntreaga.begin(),
		carteIntreaga.end(),
		rgx,
		-1);
	sregex_token_iterator end;

	for (; iter != end; ++iter)
		map[*iter]++;*/



	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";
	char *token;

	token = strtok(&aux[0], separatori);
	while (token != NULL)
	{
		string toPush = token;
		map[toPush]++;
		token = strtok(NULL, separatori);
	}

	cout << "Creare map de un cuvant" << endl;
	/*ofstream fout("cuvinte.txt");
	for (auto elem : map)
	{
		fout << elem.first << " " << elem.second << endl;
	}
	fout.close();*/


}

void Book::creare2Vector()
{

	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";

	char *cuvant1;
	char *cuvant2;


	cuvant1 = strtok(&aux[0], separatori);
	cuvant2 = strtok(NULL, separatori);

	while (cuvant2 != NULL)
	{


		string toPush = cuvant1;
		toPush += " ";
		toPush += cuvant2;

		vector.push_back(toPush);
		cuvant1 = cuvant2;
		cuvant2 = strtok(NULL, separatori);
	}
	cout << "Creare vector de 2 cuvinte" << endl;
	/*ofstream fout("cuvinte.txt");
	for each (auto s in vector)
	{
		fout << s << endl;
	}
	fout.close();*/
}

void Book::creare2Map()
{

	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";

	char *cuvant1;
	char *cuvant2;


	cuvant1 = strtok(&aux[0], separatori);
	cuvant2 = strtok(NULL, separatori);

	while (cuvant2 != NULL)
	{
		string toPush = cuvant1;
		toPush += " ";
		toPush += cuvant2;
		map[toPush]++;
		cuvant1 = cuvant2;
		cuvant2 = strtok(NULL, separatori);
	}
	cout << "Creare map de 2 cuvinte" << endl;
	/*ofstream fout("cuvinte.txt");
	for (auto elem : map)
	{
		fout << elem.first << " " << elem.second << endl;
	}
	fout.close();*/
}

void Book::creare3Vector()
{

	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";

	char *cuvant1;
	char *cuvant2;
	char *cuvant3;

	cuvant1 = strtok(&aux[0], separatori);
	cuvant2 = strtok(NULL, separatori);
	cuvant3 = strtok(NULL, separatori);

	while (cuvant3 != NULL)
	{


		string toPush = cuvant1;
		toPush += " ";
		toPush += cuvant2;
		toPush += " ";
		toPush += cuvant3;

		vector.push_back(toPush);
		cuvant1 = cuvant2;
		cuvant2 = cuvant3;
		cuvant3 = strtok(NULL, separatori);
	}
	cout << "Creare vector de 3 cuvinte" << endl;
	/*ofstream fout("cuvinte.txt");
	for each (auto s in vector)
	{
		fout << s << endl;
	}
	fout.close();*/
}

void Book::creare3Map()
{

	string aux = carteIntreaga;

	char separatori[] = "-:,.;(\" \n";

	char *cuvant1;
	char *cuvant2;
	char *cuvant3;


	cuvant1 = strtok(&aux[0], separatori);
	cuvant2 = strtok(NULL, separatori);
	cuvant3 = strtok(NULL, separatori);

	while (cuvant3 != NULL)
	{
		string toPush = cuvant1;
		toPush += " ";
		toPush += cuvant2;
		toPush += " ";
		toPush += cuvant3;
		map[toPush]++;
		cuvant1 = cuvant2;
		cuvant2 = cuvant3;
		cuvant3 = strtok(NULL, separatori);
	}
	cout << "Creare map de 3 cuvinte" << endl;
	/*ofstream fout("cuvinte.txt");
	for (auto elem : map)
	{
		fout << elem.first << " " << elem.second << endl;
	}
	fout.close();*/
}



void Book::mostCommonWordVector() 
{
	std::vector<string> aux;  
	aux = vector;

	std::sort(aux.begin(), aux.end());
	std::unique(aux.begin(), aux.end());


	int maxAparitii = 0;
	string maxCuvant;

	for each(auto cuvant in aux)
	{
		int aparitiiCuvant = std::count(vector.begin(), vector.end(), cuvant);
		if (aparitiiCuvant > maxAparitii)
		{
			maxAparitii = aparitiiCuvant;
			maxCuvant = cuvant;
			
		}
	}
	
	cout << "Cel mai comun cuvant din vector : " << maxCuvant << " apare de " << maxAparitii << endl;


}

void Book::mostCommonWordMap()
{

	int maxAparitii = 0;
	string maxCuvant;
	for each (auto s in map)
	{
		if (s.second > maxAparitii)
		{
			maxAparitii = s.second;
			maxCuvant = s.first;
		}
	}

	cout << "Cel mai comun cuvant din map : " << maxCuvant << " " << maxAparitii << endl;
}

void Book::wordExistsVector(string word)
{
	if (std::find(vector.begin(), vector.end(), word) != vector.end())
		cout << "Cuvantul " << word << " din vector exista" << endl;
	else
		cout << "Cuvantul " << word << " din vector nu exista" << endl;
}

void Book::wordExistsMap(string word)
{
	if (map[word] != 0)
		cout << "Cuvantul " << word << " din map exista" << endl;
	else
		cout << "Cuvantul " << word << " din map nu exista" << endl;

}

void Book::wordsAppearsVector(int n)
{
	std::vector<string> aux;
	aux = vector;

	std::sort(aux.begin(), aux.end());
	std::unique(aux.begin(), aux.end());

	cout << "Cuvintele din vector care apar de mai mult de " << n << " ori :" << endl;

	for each(auto cuvant in aux)
	{
		int aparitiiCuvant = std::count(vector.begin(), vector.end(), cuvant);
		if (aparitiiCuvant > n)
		{
			cout << cuvant << " " << aparitiiCuvant << endl;
		}
	}
}

void Book::wordsAppearsMap(int n)
{
	cout << "Cuvintele din map care apar de mai mult  de " << n << " ori :" << endl;
	for each (auto s in map)
	{
		if (s.second > n)
		{
			cout << s.first << " " << s.second << endl;
		}
	}
}

void Book::wordCountVector(string cuvant)
{
	int aparitiiCuvant = std::count(vector.begin(), vector.end(), cuvant);
	cout << "Cuvantul " << cuvant << " apare de  " << aparitiiCuvant << " ori in vector"<< endl;
}

void Book::wordCountMap(string cuvant)
{
	cout << "Cuvantul " << cuvant << " apare de " << map[cuvant] << " ori in map" << endl;
}



void Book::profileMethod(void(Book::*functie)())
{

	auto start = std::chrono::high_resolution_clock::now();

	(this->*functie)();

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	cout << "This took " << duration.count() << " milliseconds " << endl;

}

void Book::profileMethod(void(Book::* functie)(int), int n)
{
	auto start = std::chrono::high_resolution_clock::now();

	(this->*functie)(n);

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	cout << "This took " << duration.count() << " milliseconds " << endl;
}

void Book::profileMethod(void(Book::* functie)(string), string s)
{
	auto start = std::chrono::high_resolution_clock::now();

	(this->*functie)(s);

	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now() - start);
	cout << "This took " << duration.count() << " milliseconds " << endl;
}




