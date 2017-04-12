#pragma once
#include <string>
class Discount
{
public:
	Discount();
	static auto getServiceDiscount(const std::string type)->double;
	static auto getProductDiscount(const std::string type)->double;
	~Discount();

private:
	static const double serviceDiscountPremium;
	static const double serviceDiscountGold;
	static const double serviceDiscountSilver;
	static const double productDiscountPremium;;
	static const double productDiscountGold;
	static const double productDiscountSilver;

};

