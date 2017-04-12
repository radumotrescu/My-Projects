#include "Discount.h"

double Discount::serviceDiscountPremium = 0.2;
double Discount::serviceDiscountGold = 0.15;
double Discount::serviceDiscountSilver = 0.1;
double Discount::productDiscountPremium = 0.1;
double Discount::productDiscountGold = 0.1;
double Discount::productDiscountSilver = 0.1;

Discount::Discount()
{
}

auto Discount::getServiceDiscount(std::string type) -> double
{
	if (type == "Premium")
	{
		return serviceDiscountPremium;
	}
	else if (type == "Gold")
	{
		return serviceDiscountGold;
	}
	else if (type == "Silver")
	{
		return serviceDiscountSilver;
	}
	else
		return 0.0;
}

auto Discount::getProductDiscount(std::string type) -> double
{
	if (type == "Premium")
	{
		return productDiscountPremium;
	}
	else if (type == "Gold")
	{
		return productDiscountGold;
	}
	else if (type == "Silver")
	{
		return productDiscountSilver;
	}
	else
		return 0.0;
}


Discount::~Discount()
{
	delete this;
}
