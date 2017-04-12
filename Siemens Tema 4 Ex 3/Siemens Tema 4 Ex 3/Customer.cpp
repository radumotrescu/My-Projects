#include "Customer.h"



Customer::Customer(std::string name)
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

auto Customer::setMember(bool member) -> void
{
	this->member = member;
}

auto Customer::getMemberType() -> std::string
{
	return memberType;
}

auto Customer::setMemberType(std::string type) -> void
{
	this->memberType = type;
}

auto Customer::toString() -> std::string
{
	std::string toReturn="";
	toReturn += name;
	toReturn += " ";
	toReturn += member;
	toReturn += " ";
	toReturn += memberType;
	toReturn += '\n';
	return toReturn;
}

Customer::~Customer()
{
	delete this;

}
