#include "Service.h"
#include <algorithm>
#include <iostream>

ServiceProduct::ServiceProduct()noexcept
{

}

ServiceProduct::ServiceProduct(RepositoryProduct rep)
{
	this->repo = rep;
}

int ServiceProduct::getSize()noexcept
{
	return repo.sizeVector();
}

std::vector<Product> ServiceProduct::searchProduct(std::string name, std::string type, int price, std::string producer)
{
	std::vector<Product> vec{ 1 };
	std::copy_if(repo.getAll().begin(), repo.getAll().end(), vec.begin(), [name, type, price, producer](Product p) 
	{return p.getName() == name && p.getType() == type && p.getPrice() == price && p.getProducer() == producer; });
	return vec;
}

void ServiceProduct::addProduct(std::string name, std::string type, int price, std::string producer)
{
	Product p = Product(name, type, price, producer);
	val.validateProduct(p);
	repo.add(p);
}

void ServiceProduct::modifyProduct(std::string nameI, std::string typeI, std::string producerI, std::string name, std::string type, int price, std::string producer)
{
	Product pInitial = Product(nameI, typeI, 1, producerI);
	Product p = Product(name, type, price, producer);
	val.validateProduct(pInitial);
	val.validateProduct(p);
	repo.modify(pInitial, p);
}

void ServiceProduct::removeProduct(std::string name, std::string type, int price, std::string producer)
{
	Product p = Product(name, type, price, producer);
	val.validateProduct(p);
	repo.remove(p);
}

std::vector<Product> ServiceProduct::filterPrice(int price)
{
	std::vector<Product> vector2{ repo.getAll().size() };
	auto it = std::copy_if(repo.getAll().begin(), repo.getAll().end(), vector2.begin(),[price](Product p) noexcept{return p.getPrice() >= price; });
	vector2.resize(std::distance(vector2.begin(), it));
	return vector2;
}

std::vector<Product> ServiceProduct::filterName(std::string name)
{
	std::vector<Product> vector2{ repo.getAll().size() };
	auto it = std::copy_if(repo.getAll().begin(), repo.getAll().end(), vector2.begin(), [name](Product p) noexcept {return p.getName() == name; });
	vector2.resize(std::distance(vector2.begin(), it));
	return vector2;
}

std::vector<Product> ServiceProduct::filterProducer(std::string producer)
{
	std::vector<Product> vector2{ repo.getAll().size() };
	auto it = std::copy_if(repo.getAll().begin(), repo.getAll().end(), vector2.begin(), [producer](Product p) noexcept {return p.getProducer() == producer; });
	vector2.resize(std::distance(vector2.begin(), it));
	return vector2;
}

std::vector<Product> ServiceProduct::genericSort(relation r)
{
	std::vector<Product> vectorSortat = copyVector();
	std::sort(vectorSortat.begin(), vectorSortat.end(), r);
	return vectorSortat;
}

std::vector<Product> ServiceProduct::biggerPrice()noexcept
{
	return genericSort(cmpBiggerPrice);
}

std::vector<Product> ServiceProduct::smallerPrice()noexcept
{
	return genericSort(cmpSmallerPrice);
}

std::vector<Product> ServiceProduct::biggerName()noexcept
{
	return genericSort(cmpBiggerName);
}

std::vector<Product> ServiceProduct::smallerName()noexcept
{
	return genericSort(cmpSmallerName);
}

std::vector<Product> ServiceProduct::biggerType()noexcept
{
	return genericSort(cmpBiggerType);
}

std::vector<Product> ServiceProduct::smallerType()noexcept
{
	return genericSort(cmpSmallerType);
}

std::vector<Product> ServiceProduct::copyVector()
{
	std::vector<Product> vec{repo.getAll().size()};
	auto it = std::copy_if(repo.getAll().begin(), repo.getAll().end(), vec.begin(), [](Product p) noexcept{return p.getPrice() > 0; });
	//vec.resize(std::distance(vec.begin(),it));
	return vec;
}

const std::vector<Product>& ServiceProduct::getAllS()noexcept
{
	return repo.getAll();
}

void ServiceProduct::addListService(std::vector<Product>& list, std::string name)
{
	repo.addList(list, name);
}

void ServiceProduct::clearListService(std::vector<Product>& list)noexcept
{
	repo.removeList(list);
}

void ServiceProduct::generateList(std::vector<Product>& list, int n)
{
	repo.generate(list, n);
}

/*
std::vector<Product> ServiceProduct::sortareprice(int optiune)
{
	std::vector<Product> vectorSortat = copyVector();
	if (optiune == 1)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getPrice() < p2.getPrice(); });
	else if (optiune == 0)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getPrice() > p2.getPrice(); });
	return vectorSortat;
}

std::vector<Product> ServiceProduct::sortarename(int optiune)
{
	std::vector<Product> vectorSortat = copyVector();
	if (optiune == 1)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getName() < p2.getName(); });
	else if (optiune == 0)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getName() > p2.getName(); });
	return vectorSortat;
}

std::vector<Product> ServiceProduct::sortarenametype(int optiune)
{
	std::vector<Product> vectorSortat = copyVector();
	if (optiune == 1)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getName() < p2.getName() && p1.getType() < p2.getType(); });
	else if (optiune == 0)
		std::sort(vectorSortat.begin(), vectorSortat.end(), [](Product p1, Product p2) noexcept {return p1.getName() > p2.getName() && p1.getType() > p2.getType(); });
	return vectorSortat;
}
*/
