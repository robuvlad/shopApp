#include "Produs.h"

Product::Product() noexcept{
	this->name = "";
	this->type = "";
	this->price = 0;
	this->producer = "";
}

Product::Product(const std::string name, const std::string type, const int price, const std::string producer)
{
	this->name = name;
	this->type = type;
	this->price = price;
	this->producer = producer;
}

int Product::getPrice()const noexcept
{
	return this->price;
}

void Product::setPrice(int pre)noexcept
{
	this->price = pre;
}

std::string Product::getName()const
{
	return this->name;
}

void Product::setName(std::string num)
{
	this->name = num;
}

std::string Product::getType()const
{
	return this->type;
}

void Product::setType(std::string ti)
{
	this->type = ti;
}

std::string Product::getProducer()const
{
	return this->producer;
}

void Product::setProducer(std::string produc)
{
	this->producer = produc;
}

bool cmpSmallerPrice(const Product & p1, const Product & p2)noexcept
{
	return p1.getPrice() < p2.getPrice();
}

bool cmpBiggerPrice(const Product & p1, const Product & p2) noexcept
{
	return p1.getPrice() > p2.getPrice();
}

bool cmpSmallerName(const Product & p1, const Product & p2) noexcept
{
	return p1.getName() < p2.getName();
}

bool cmpBiggerName(const Product & p1, const Product & p2) noexcept
{
	return p1.getName() > p2.getName();
}

bool cmpSmallerType(const Product & p1, const Product & p2) noexcept
{
	return p1.getName() < p2.getName() && p1.getType() < p2.getType();
}

bool cmpBiggerType(const Product & p1, const Product & p2) noexcept
{
	return p1.getName() > p2.getName() && p1.getType() > p2.getType();
}
