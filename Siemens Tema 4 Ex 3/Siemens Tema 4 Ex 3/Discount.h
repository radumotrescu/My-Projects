#pragma once
#include <string>
class Discount
{
public:
	Discount();
	static auto getServiceDiscount(std::string type)->double;
	static auto getProductDiscount(std::string type)->double;
	~Discount();

private:
	static double serviceDiscountPremium;
	static double serviceDiscountGold;
	static double serviceDiscountSilver;
	static double productDiscountPremium;;
	static double productDiscountGold;
	static double productDiscountSilver;

};

