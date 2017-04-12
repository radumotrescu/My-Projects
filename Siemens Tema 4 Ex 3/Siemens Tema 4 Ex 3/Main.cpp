#include <iostream>
#include <memory>
#include "Visit.h"
#include "Customer.h"
#include "Discount.h"


int main()
{

	auto firstCustomer = std::unique_ptr<Customer>(new Customer("Radu"));
	firstCustomer->setMember(true);
	firstCustomer->setMemberType("Premium");
	auto secondCustomer = std::unique_ptr<Customer>(new Customer("Rares"));
	secondCustomer->setMember(true);
	secondCustomer->setMemberType("Gold");
	auto thirdCustomer = std::unique_ptr<Customer>(new Customer("Miruna"));
	thirdCustomer->setMember(true);
	thirdCustomer->setMemberType("Silver");
	auto fourthCustomer = std::unique_ptr<Customer>(new Customer("Vladut"));
	fourthCustomer->setMember(false);
	fourthCustomer->setMemberType("Silver"); // nu o sa poata face asta pentru ca nu e membru

	// fiecare customer va avea de platit fie 100 de bani de servicii, fie de produse, fie de ambele
	// mai jos se poate vedea care sunt sumele platite in final de fiecare customer


	Visit *visit1 = new Visit(std::move(firstCustomer), boost::gregorian::day_clock::local_day());
	visit1->setServiceExpense(100.0);
	std::cout << visit1->toString();
	std::cout << std::endl;

	Visit *visit2 = new Visit(std::move(secondCustomer), boost::gregorian::day_clock::local_day());
	visit2->setProductExpense(100.0);
	std::cout << visit2->toString();
	std::cout << std::endl;

	Visit *visit3 = new Visit(std::move(thirdCustomer), boost::gregorian::day_clock::local_day());
	visit3->setServiceExpense(100.0);
	visit3->setProductExpense(100.0);
	std::cout << visit3->toString();
	std::cout << std::endl;

	Visit *visit4 = new Visit(std::move(fourthCustomer), boost::gregorian::day_clock::local_day());
	visit4->setServiceExpense(100.0);
	visit4->setProductExpense(100.0);
	std::cout << visit4->toString();
	std::cout << std::endl;

	return 0;
}