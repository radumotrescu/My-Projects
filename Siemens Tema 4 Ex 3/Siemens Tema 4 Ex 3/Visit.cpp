#include "Visit.h"

Visit::Visit(std::string name, boost::gregorian::date date)
{
	this->date = date;


}

auto Visit::getName() -> std::string
{
	return customer->getName();
}

auto Visit::getServiceExpense() -> double
{
	return serviceExpense;
}

auto Visit::setServiceExpense(double ex) -> void
{
	double serviceDiscount = Discount::getServiceDiscount(customer->getMemberType());
	ex -= ex*serviceDiscount;
	serviceExpense = ex;
}

auto Visit::getProductExpense() -> double
{
	return productExpense;
}

auto Visit::setProductExpense(double ex) -> void
{
	double productDiscount = Discount::getProductDiscount(customer->getMemberType());
	ex -= ex*productDiscount;
	productExpense = ex;
	
}

auto Visit::getTotalExpense() -> double
{
	return serviceExpense + productExpense;
}

auto Visit::toString() -> std::string
{

	std::string toReturn = "";
	toReturn += customer->toString();
	toReturn += " ";
	toReturn += boost::gregorian::to_simple_string(date);
	toReturn += " ";
	toReturn += getTotalExpense();
	toReturn += " ";

	return toReturn;
}


Visit::~Visit()
{
	delete this;
}