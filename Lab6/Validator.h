#ifndef VALIDATOR_H
#define VALIDATOR_H

#include <vector>
#include <string>
#include "Produs.h"

class ValidatorProduct {
public:
	void validateProduct(const Product& p);
};

class ValidatorException {
private:
	std::string message;
public:
	ValidatorException(const std::string& m) :message{ m } {};
	const std::string& getMessage() const noexcept{ return message; }
	//friend std::ostream& operator<<(std::ostream& out, const ValidatorException& ex);
};

//std::ostream& operator<<(std::ostream& out, const ValidatorException& ex);

#endif