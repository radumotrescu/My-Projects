#include "Visit.h"

Visit::Visit(std::unique_ptr<Customer>customer, const boost::gregorian::date date)
{
	this->date = date;
	this->customer = std::move(customer);
}

auto Visit::getName() -> std::string
{
	return customer->getName();
}

auto Visit::getServiceExpense() -> double
{
	return serviceExpense;
}

auto Visit::setServiceExpense(const double ex) -> void
{
	if (customer->isMember())
	{
		double serviceDiscount = Discount::getServiceDiscount(customer->getMemberType());
		serviceExpense = ex - ex*serviceDiscount;
	}
}

auto Visit::getProductExpense() -> double
{
	return productExpense;
}

auto Visit::setProductExpense(const double ex) -> void
{
	if (customer->isMember())
	{
		double productDiscount = Discount::getProductDiscount(customer->getMemberType());
		productExpense = ex - ex*productDiscount;
	}
}

auto Visit::getTotalExpense() -> double
{
	return serviceExpense + productExpense;
}

auto Visit::toString() -> std::string
{
	std::string toReturn = "";
	toReturn += customer->toString();
	toReturn += boost::gregorian::to_simple_string(date);
	toReturn += " ";
	toReturn += std::to_string(getTotalExpense());
	toReturn += "\n";

	return toReturn;
}


Visit::~Visit()
{

}