#ifndef SERVICE_H
#define SERVICE_H // define SERVICE_H if it is not defined

#include "Repository.h"
#include "Validator.h"
#include <memory>

typedef bool(*relation)(const Product&, const Product&);

/*
this class makes an association with the repository
*/
class ServiceProduct {
private:
	RepositoryProduct repo;
	ValidatorProduct val;
public:
	ServiceProduct()noexcept;
	/*
	the constructor of the class
	*/
	ServiceProduct(RepositoryProduct rep);

	/*
	returns the size of the vector
	*/
	int getSize()noexcept;

	/*
	returns the product with certain name, type, price and producer
	*/
	std::vector<Product> searchProduct(std::string name, std::string type, int price, std::string producer);

	/*
	adds a product to the vector
	*/
	void addProduct(std::string name, std::string type, int price, std::string producer);

	/*
	modifies a product in the vector
	*/
	void modifyProduct(std::string nameI, std::string typeI, std::string producerI, std::string name, std::string type, int price, std::string producer);

	/*
	removes a product from the vector if it exists
	*/
	void removeProduct(std::string name, std::string type, int price, std::string producer);

	/*
	search for the products that have a bigger price
	*/
	std::vector<Product> filterPrice(int price);

	/*
	search for the products that have a certain name
	*/
	std::vector<Product> filterName(std::string name);

	/*
	search for the products that have a certain producer
	*/
	std::vector<Product> filterProducer(std::string producer);

	/*
	generic sort for sorting the vector by a condition
	*/
	std::vector<Product> genericSort(relation r);

	/*
	sorting the vector of products by price descending
	*/
	std::vector<Product> biggerPrice()noexcept;

	/*
	sorting the vector of products by price ascending
	*/
	std::vector<Product> smallerPrice()noexcept;

	/*
	sorting the vector of products by name descending
	*/
	std::vector<Product> biggerName()noexcept;

	/*
	sorting the vector of products by price ascending
	*/
	std::vector<Product> smallerName()noexcept;

	/*
	sorting the vector of products by type descending
	*/
	std::vector<Product> biggerType()noexcept;

	/*
	sorting the vector of products by price ascending
	*/
	std::vector<Product> smallerType()noexcept;

	/*
	returns a copy of the vector of products
	*/
	std::vector<Product> copyVector();

	/*
	returns the vector from the repo
	*/
	const std::vector<Product>& getAllS()noexcept;

	/*
	adds an element in the list
	*/
	void addListService(std::vector<Product>& list, std::string name);

	/*
	clear the entire list
	*/
	void clearListService(std::vector<Product>& list)noexcept;

	/*
	generate a random list with the existed elements in the vector
	*/
	void generateList(std::vector<Product>& list, int n);

	/*
	sorts the vector of products by price

	std::vector<Product> sortareprice(int optiune);

	/*
	sorts the vector of products by name
	
	std::vector<Product> sortarename(int optiune);

	/*
	sorts the vector of products by type
	
	std::vector<Product> sortarenametype(int optiune);
	*/
};

#endif