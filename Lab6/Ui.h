#ifndef UI_H
#define UI_H // define UI_H if it is not defined

#include "Service.h"

/*
this class makes an association with the service class
*/
class Ui {
private:
	ServiceProduct service;
public:
	Ui()noexcept;
	/*
	the constructor of the class
	*/
	Ui(ServiceProduct ser);

	/*
	the menu of the application
	*/
	void ui_menu();

	/*
	some data stored
	*/
	void ui_data(Ui& ui);

	/*
	print all products
	*/
	void ui_printProducts();

	/*
	add a product
	*/
	void ui_addProduct(Ui& ui);

	/*
	modify a product
	*/
	void ui_modifyProduct(Ui& ui);

	/*
	remove a product
	*/
	void ui_removeProduct(Ui& ui);

	/*
	searching in the products that have a bigger price
	*/
	void ui_filterPrice(Ui& ui);

	/*
	searching in the products that have a certain name
	*/
	void ui_filterName(Ui& ui);

	/*
	searching in the products that have a certain producer
	*/
	void ui_filterProducer(Ui& ui);

	/*
	sorting the vector by giving the price
	0 - for sorting the vector ascending
	1 - for sorting the vector descending
	*/
	void ui_sortByPrice(Ui& ui);

	/*
	sorting the vector by giving the name
	0 - for sorting the vector ascending
	1 - for sorting the vector descending
	*/
	void ui_sortByName(Ui& ui);

	/*
	sorting the vector by giving the type
	0 - for sorting the vector ascending
	1 - for sorting the vector descending
	*/
	void ui_sortByType(Ui& ui);

	/*
	searches for a certain product
	*/
	void ui_searchProduct(Ui& ui);

	/*
	adds an element in the list
	*/
	void ui_addList(Ui& ui, std::vector<Product>& cos);

	/*
	clear the entire list
	*/
	void ui_clearList(Ui& ui, std::vector<Product>& cos);

	/*
	generate a random list with the existed elements in the vector
	*/
	void ui_generateList(Ui& ui, std::vector<Product>& cos);
};

#endif