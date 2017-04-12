#include "Customer.h"

Customer::Customer(const std::string name)
{
	this->name = name;
}

auto Customer::getName() -> std::string
{
	return name;
}

auto Customer::isMember() -> bool
{
	return member;
}

auto Customer::setMember(const bool member) -> void
{
	this->member = member;
}

auto Customer::getMemberType() -> std::string
{
	return memberType;
}

auto Customer::setMemberType(const std::string type) -> void
{
	if (member == true)
	{
		if (type == "Premium" || type == "Gold" || type == "Silver")
			this->memberType = type;
		return;
	}
	this->memberType = "Not a member";
}

auto Customer::toString() -> std::string
{
	std::string toReturn = "";
	toReturn += name;
	toReturn += " ";
	toReturn += std::to_string(member);
	toReturn += " ";
	toReturn += memberType;
	toReturn += '\n';
	return toReturn;
}

Customer::~Customer()
{

}
