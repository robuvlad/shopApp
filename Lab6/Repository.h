#ifndef REPOSITORY_H
#define REPOSITORY_H // define REPOSITORY_H if it is not defined

#include "Produs.h"
#include <vector>
#include<memory>

/*
Vector of products
*/
class RepositoryProduct {
private:
	std::vector<Product> vector;
public:
	/*
	the constructor of the class
	*/
	RepositoryProduct()=default;

	/*
	returns an integer: the size of the vector
	*/
	int sizeVector()noexcept;

	/*
	verifies if the product exists
	*/
	bool checkProduct(Product p);

	/*
	adds a product to the vector
	*/
	void add(Product p);

	/*
	modifies a product
	pInitial is the initial product and p is the new product
	*/
	void modify(Product pInitial, Product p);

	/*
	delets a product from the vector
	*/
	void remove(Product p);

	/*
	returns the entire vector of products
	*/
	const std::vector<Product>& getAll()noexcept;

	/*
	adds an element in the list
	*/
	void addList(std::vector<Product>& list, std::string name);

	/*
	clears the entire list
	*/
	void removeList(std::vector<Product>& list)noexcept;

	/*
	generates a random list
	*/
	void generate(std::vector<Product>& list, int n);

};

class RepositoryException {
private:
	std::string message;
public:
	RepositoryException(const std::string& msj) : message{ msj }{};
	const std::string& getMessage() const noexcept{ return message; }
	//friend std::ostream& operator<<(std::ostream& out, const RepositoryException& ex);
};

//std::ostream& operator<<(std::ostream& out, const RepositoryException& ex);

#endif