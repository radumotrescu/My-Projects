#include "Book.h"
#include <memory>



int main()
{
	std::unique_ptr<Book> pointerBook(std::make_unique<Book>());

	pointerBook->citire();



	/*pointerBook->profileMethod(&(Book::creareMap));
	pointerBook->profileMethod(&(Book::mostCommonWordMap));
	pointerBook->profileMethod(&(Book::wordsAppearsMap), 200);
	pointerBook->profileMethod(&(Book::wordCountMap), "Elizabeth");
	pointerBook->profileMethod(&(Book::wordExistsMap), "Elizabeth");


	pointerBook->profileMethod(&(Book::creareVector));
	pointerBook->profileMethod(&(Book::mostCommonWordVector));
	pointerBook->profileMethod(&(Book::wordsAppearsVector), 200);
	pointerBook->profileMethod(&(Book::wordCountVector), "Elizabeth");
	pointerBook->profileMethod(&(Book::wordExistsVector), "Elizabeth");*/


	//pointerBook->profileMethod(&(Book::creare2Vector));
	//pointerBook->profileMethod(&(Book::creare2Map));
	//pointerBook->profileMethod(&(Book::creare3Vector));
	//pointerBook->profileMethod(&(Book::creare3Map));

	// merg si restul de operatii pe vectorul/mapul care contine secvente de 2-3 cuvinte
	//pointerBook->profileMethod(&(Book::mostCommonWordVector));
	//pointerBook->profileMethod(&(Book::mostCommonWordMap));


	return 0;

}