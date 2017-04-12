#pragma once
#include <boost\date_time\gregorian\gregorian.hpp>
#include <string>
#include <memory>
#include "Customer.h"
#include "Discount.h"

class Visit
{
public:

	Visit(std::unique_ptr<Customer> customer, const boost::gregorian::date date);
	auto getName()->std::string;
	auto getServiceExpense()->double;
	auto setServiceExpense(const double ex)->void;
	auto getProductExpense()->double;
	auto setProductExpense(const double ex)->void;
	auto getTotalExpense()->double;
	auto toString()->std::string;
	~Visit();

private:
	std::unique_ptr<Customer> customer;
	boost::gregorian::date date;
	double serviceExpense = 0;
	double productExpense = 0;
};

