#include <iostream>
#include "Visit.h"
#include "Customer.h"
#include "Discount.h"

int main()
{
	std::list<Customer*> customerList;


	Customer *a = new Customer("Radu");
	a->setMember(true);
	a->setMemberType("Premium");
	Customer *b = new Customer("Radu");
	b->setMember(true);
	b->setMemberType("Premium");
	Customer *c = new Customer("Radu");
	c->setMember(true);
	c->setMemberType("Premium");
	Customer *d = new Customer("Radu");
	d->setMember(true);
	d->setMemberType("Premium");


	customerList.push_back(a);
	customerList.push_back(b);
	customerList.push_back(c);
	customerList.push_back(d);

	Visit *vizita1 = new Visit(a, boost::gregorian::day_clock::local_day());
	vizita1->setProductExpense(100.0);
	std::cout << vizita1->toString();



	return 0;
}