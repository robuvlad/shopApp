#include "Repository.h"
#include <string>
#include <iostream>
#include <algorithm>

int RepositoryProduct::sizeVector()noexcept
{
	return vector.size();
}

bool RepositoryProduct::checkProduct(Product p)
{
	if (std::any_of(vector.begin(), vector.end(), [p](Product anotherP)
	{return p.getName() == anotherP.getName() && p.getType() == anotherP.getType() && p.getProducer() == anotherP.getProducer(); }))
		return true;
	return false;
}

void RepositoryProduct::add(Product p)
{
	if (checkProduct(p) == false)
		vector.push_back(p);
	else
		throw RepositoryException("The element exists !\n");
}

void RepositoryProduct::modify(Product pInitial, Product p)
{
	if (checkProduct(pInitial) == true)
		std::replace(vector.begin(), vector.end(), pInitial, p);
	else
		throw RepositoryException("The element does not exist !\n");
}

void RepositoryProduct::remove(Product p)
{
	if (checkProduct(p) == true)
		vector.erase(std::remove(vector.begin(), vector.end(), p), vector.end());
	else
		throw RepositoryException("The element does not exist !\n");
}

const std::vector<Product>& RepositoryProduct::getAll()noexcept
{
	return vector;
}

void RepositoryProduct::addList(std::vector<Product>& list, std::string name)
{
	std::for_each(vector.begin(), vector.end(), [name, &list](Product p) {if (p.getName() == name) list.push_back(p); });
}

void RepositoryProduct::removeList(std::vector<Product>& list)noexcept
{
	list.clear();
}

void RepositoryProduct::generate(std::vector<Product>& list, int n)
{
	int j = 1;
	std::for_each(vector.begin(), vector.end(), [&list, n, &j](Product p) {if (j == n) list.push_back(p); j += 1; });
}
/*
std::ostream & operator<<(std::ostream & out, const RepositoryException & ex)
{
	out << ex.mesaj;
	return out;
}
*/
