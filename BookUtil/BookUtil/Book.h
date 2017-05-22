#ifndef _BOOK_H_
#define _BOOK_H_

#include <string>
#include <iostream>
#include <vector>
#include <map>



using namespace std;

class Book
{

public:
	Book();
	~Book();

	void citire();
	void afisare();
	void creareVector();
	void creareMap();
	void creare2Vector();
	void creare2Map();
	void creare3Vector();
	void creare3Map();
	void mostCommonWordVector();
	void mostCommonWordMap();
	void wordsAppearsVector(int n);
	void wordsAppearsMap(int n);
	void wordCountVector(string cuvant);
	void wordCountMap(string cuvant);
	void wordExistsVector(string word);
	void wordExistsMap(string word);
	void profileMethod(void(Book::*functie)());
	void profileMethod(void(Book::*functie)(int), int n);
	void profileMethod(void(Book::*functie)(string), string s);




private:

	string carteIntreaga;
	vector<string> vector;
	map<string, int> map;

};

#endif