#include <iostream>
#include "Visit.h"
#include "Customer.h"
#include "Discount.h"

int main()
{
	Customer *a = new Customer("Radu");
	a->setMember(true);
	a->setMemberType("Premium");



	return 0;
}