#ifndef PRODUS_H
#define PRODUS_H // define PRODUS_H if it is not defined

#include <string>
/*
Produs class, where: nume, tip, producator are string and pret is an integer
*/
class Product {
private:
	std::string name;
	std::string type;
	std::string producer;
	int price;
public:
	/*
	empty constructor
	*/
	Product()noexcept;

	/*
	constructor of the class
	*/
	Product(const std::string name, const std::string type, const int price, const std::string producer);

	bool operator==(const Product& p) noexcept{
		return p.name == name && p.price == price && p.producer == producer && p.type == type;
	}
	//Produs(const Produs& p) : nume{ p.nume }, tip{ p.tip }, producator{ p.producator }, pret{ p.pret } {};

	/*
	Produs& operator=(const Produs& p) {
		nume = p.nume;
		tip = p.tip;
		producator = p.producator;
		pret = p.pret;
		return *this;
	}
	*/

	/*
	getter function for the price
	*/
	int getPrice()const noexcept;

	/*
	setter function for the price
	*/
	void setPrice(int pre)noexcept;

	/*
	getter function for the name
	*/
	std::string getName()const;

	/*
	setter function for the name
	*/
	void setName(std::string num);

	/*
	getter function for the type
	*/
	std::string getType()const;

	/*
	setter function for the type
	*/
	void setType(std::string ti);

	/*
	getter function for the producer
	*/
	std::string getProducer()const;

	/*
	setter function for the producer
	*/
	void setProducer(std::string produc);
};

//compare two products by price - returns true if the first product has the price smaller than the second product
bool cmpSmallerPrice(const Product& p1, const Product& p2)noexcept;

//compare two products by price - returns true if the first product has the price bigger than the second product
bool cmpBiggerPrice(const Product& p1, const Product& p2)noexcept;

//compare two products by price - returns true if the first product has the name smaller than the second product
bool cmpSmallerName(const Product& p1, const Product& p2)noexcept;

//compare two products by price - returns true if the first product has the name bigger than the second product
bool cmpBiggerName(const Product& p1, const Product& p2)noexcept;

//compare two products by price - returns true if the first product has the type smaller than the second product
bool cmpSmallerType(const Product& p1, const Product& p2)noexcept;

//compare two products by price - returns true if the first product has the type bigger than the second product
bool cmpBiggerType(const Product& p1, const Product& p2)noexcept;

#endif