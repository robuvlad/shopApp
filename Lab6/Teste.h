#ifndef TESTE_H
#define TESTE_H

#include "Produs.h"
#include "Repository.h"
#include "Service.h"
#include "Ui.h"

/*
test class
*/
class Teste {
public:
	/*
	the constructor of the class
	*/
	Teste()noexcept;

	/*
	test for adding an element to the vector
	*/
	void testAdd();

	/*
	test for modifying an element from the vector
	*/
	void testModify();

	/*
	test for removing an element from the vector
	*/
	void testRemove();

	/*
	test for filtering out the price
	*/
	void filterPrice();

	/*
	test for filtering out the name
	*/
	void filterName();

	/*
	test for filtering out the producer
	*/
	void filterProducer();

	/*
	test for sorting the vector by price
	*/
	void sortByPrice();

	/*
	test for sorting the vector by name
	*/
	void sortByName();

	/*
	test for sorting the vector by type
	*/
	void sortByType();

	/*
	test for searching a product
	*/
	void search();

	/*
	test for adding a product in the list
	*/
	void testAddList();

	/*
	test for clearing the entire list
	*/
	void testClearList();

	/*
	test for generating the list
	*/
	void testGenerateList();

	/*
	calls all tests
	*/
	void tests();
};

#endif