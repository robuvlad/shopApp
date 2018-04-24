#include "Validator.h"
#include <vector>
#include <string>

void ValidatorProduct::validateProduct(const Product & p)
{
	std::string message;
	if (p.getPrice() <= 0)
		message += "Invalid price!\n";
	if (p.getName().size() == 0)
		message += "Invalid name!\n";
	if (p.getType().size() == 0)
		message += "Invalid type!\n";
	if (p.getProducer().size() == 0)
		message += "Invalid producer!\n";
	if (message.size() != 0)
		throw ValidatorException(message);
}
/*
std::ostream & operator<<(std::ostream & out, const ValidatorException & ex)
{
	for (const auto& messagee : ex.messagee) {
		out << messagee << " ";
	}
	return out;
}
*/
