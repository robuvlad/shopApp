#include "Teste.h"
#include <assert.h>

Teste::Teste()noexcept
{

}

void Teste::testAdd()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	assert(service.getSize() == 1);
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	assert(service.getSize() == 2);
	try {
		service.addProduct("minge", "rugby", 200, "RugbySport");}
	catch (RepositoryException& m) { assert (true);
	std::string mesaj = m.getMessage();}
	Product p{ "masina","sport",1000,"BMW" };
	p.setName("mas"); p.setType("lux"); p.setProducer("Mercedes"); p.setPrice(1500);
}

void Teste::testModify()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	std::vector<Product> v = service.getAllS();
	assert(v.at(1).getName() == "telefon");
	assert(v.at(0).getPrice() == 200);
	service.modifyProduct("minge", "rugby", "RugbySport", "minge", "fotbal", 200, "Sports");
	assert(v.at(0).getProducer() == "RugbySport");
	ValidatorProduct val = ValidatorProduct();
	Product p{ "","",-2,"" };
	try {
		val.validateProduct(p);} 
	catch (ValidatorException& v) { assert(true);
	std::string val2 = v.getMessage(); }
	try {
		service.modifyProduct("a", "b", "c", "minge", "fotbal", 250, "Sports");}
	catch (RepositoryException) {}
}

void Teste::testRemove()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	service.removeProduct("minge", "rugby", 200, "RugbySport");
	std::vector<Product> v = service.getAllS();
	assert(service.getSize() == 1);
	try {
		service.removeProduct("telefon", "rugby", 200, "RugbySport");
	}catch (RepositoryException){}
	assert(service.getSize() == 1);
}

void Teste::filterPrice()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	std::vector<Product> vect = service.filterPrice(100);
	assert(vect.size() == 2);
	std::vector<Product> vect2 = service.filterPrice(1000);
	assert(vect2.size() == 1);
}

void Teste::filterName()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	std::vector<Product> vect = service.filterName("minge");
	assert(vect.size() == 1);
	std::vector<Product> vect2 = service.filterName("altceva");
	assert(vect2.size() == 0);
}

void Teste::filterProducer()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	std::vector<Product> vect = service.filterProducer("Samsung");
	assert(vect.size() == 1);
	std::vector<Product> vect2 = service.filterProducer("altceva");
	assert(vect2.size() == 0);
}

void Teste::sortByPrice()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	service.addProduct("telefon", "mobil", 500, "Nokia");
	std::vector<Product> vect = service.smallerPrice();
	assert(vect.size() == 3);
	std::vector<Product> vect2 = service.biggerPrice();
	assert(vect.size() == 3);
	assert(vect2.at(2).getName() == "minge");
}

void Teste::sortByName()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "rugby", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	service.addProduct("laptop", "gaming", 500, "Lenovo");
	std::vector<Product> vect = service.smallerName();
	assert(vect.size() == 3);
	assert(vect.at(0).getPrice() == 500);
	std::vector<Product> vect2 = service.biggerName();
	assert(vect.size() == 3);
	assert(vect2.at(1).getName() == "minge");
}

void Teste::sortByType()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "handbal", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	service.addProduct("laptop", "gaming", 500, "Lenovo");
	std::vector<Product> vect = service.smallerType();
	assert(vect.size() == 3);
	std::vector<Product> vect2 = service.biggerType();
	assert(vect.size() == 3);
	assert(vect2.at(1).getName() == "minge");
}

void Teste::search()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct service = ServiceProduct(repo);
	service.addProduct("minge", "handbal", 200, "RugbySport");
	service.addProduct("telefon", "mobil", 5000, "Samsung");
	service.addProduct("laptop", "gaming", 500, "Lenovo");
	std::vector<Product> v = service.searchProduct("minge", "handbal", 200, "RugbySport");
	assert(v.at(0).getName() == "minge");
	assert(v.at(0).getProducer() == "RugbySport");
	std::vector<Product> v2 = service.searchProduct("minge", "fotbal", 200, "RugbySport");
	assert(v2.at(0).getPrice() == 0);
}

void Teste::testAddList()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct ser = ServiceProduct(repo);
	ser.addProduct("minge", "handbal", 200, "RugbySport");
	ser.addProduct("telefon", "mobil", 5000, "Samsung");
	ser.addProduct("laptop", "gaming", 500, "Lenovo");
	std::vector<Product> v;
	ser.addListService(v, "minge");
	assert(v.size() == 1);
	ser.addListService(v, "telefon");
	assert(v.at(0).getPrice() == 200);
}

void Teste::testClearList()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct ser = ServiceProduct(repo);
	ser.addProduct("minge", "handbal", 200, "RugbySport");
	ser.addProduct("telefon", "mobil", 5000, "Samsung");
	ser.addProduct("laptop", "gaming", 500, "Lenovo");
	std::vector<Product> v;
	ser.clearListService(v);
	assert(v.size() == 0);
}

void Teste::testGenerateList()
{
	RepositoryProduct repo = RepositoryProduct();
	ServiceProduct ser = ServiceProduct(repo);
	std::vector<Product> v;
	ser.addProduct("minge", "handbal", 200, "RugbySport");
	ser.addProduct("telefon", "mobil", 5000, "Samsung");
	ser.addProduct("laptop", "gaming", 500, "Lenovo");
	ser.generateList(v, 1);
	assert(v.size() == 1);
	assert(v.at(0).getType() == "handbal");
}

void Teste::tests()
{
	testAdd();
	testModify();
	testRemove();
	filterPrice();
	filterName();
	filterProducer();
	sortByPrice();
	sortByName();
	sortByType();
	search();
	testAddList();
	testClearList();
	testGenerateList();
}
