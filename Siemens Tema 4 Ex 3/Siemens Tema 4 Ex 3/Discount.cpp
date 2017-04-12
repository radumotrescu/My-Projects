#include "Discount.h"

double const Discount::serviceDiscountPremium = 0.2;
double const Discount::serviceDiscountGold = 0.15;
double const Discount::serviceDiscountSilver = 0.1;

double const Discount::productDiscountPremium = 0.1;
double const Discount::productDiscountGold = 0.1;
double const Discount::productDiscountSilver = 0.1;

Discount::Discount()
{
}

auto Discount::getServiceDiscount(const std::string type) -> double
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

auto Discount::getProductDiscount(const std::string type) -> double
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

}
