#pragma once
#include <string>

class Customer
{
public:
	Customer(const std::string name);
	auto getName()->std::string;
	auto isMember()->bool;
	auto setMember(const bool member)->void;
	auto getMemberType()->std::string;
	auto setMemberType(std::string type)->void;
	auto toString()->std::string;
	~Customer();

private:

	std::string name;
	bool member = false;
	std::string memberType;
};

