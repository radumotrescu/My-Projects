#pragma once
#include <boost\date_time\gregorian\gregorian.hpp>
#include <string>
#include <list>
#include "Customer.h"
#include "Discount.h"

class Visit
{
public:


	Visit(std::string name, boost::gregorian::date date);
	auto getName()->std::string;
	auto getServiceExpense()->double;
	auto setServiceExpense(double ex)->void;
	auto getProductExpense()->double;
	auto setProductExpense(double ex)->void;
	auto getTotalExpense()->double;
	auto toString()->std::string;
	~Visit();

private:
	Customer *customer;
	boost::gregorian::date date;
	double serviceExpense;
	double productExpense;
};

