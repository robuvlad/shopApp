#include <iostream>
#include <string>
#include "Produs.h"
#include "Ui.h"
#include "Teste.h"
#include "Validator.h"
#include <memory>
#include <random>

#include <algorithm>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

Ui::Ui()noexcept
{

}

Ui::Ui(ServiceProduct ser)
{
	this->service = ser;
}

void Ui::ui_menu()
{
	std::cout << "1. Print all products" << std::endl;
	std::cout << "2. Add a product" << std::endl;
	std::cout << "3. Modify a Product" << std::endl;
	std::cout << "4. Remove a Product" << std::endl;
	std::cout << "5. Filter by price" << std::endl;
	std::cout << "6. Filter by name" << std::endl;
	std::cout << "7. Filter by producer" << std::endl;
	std::cout << "8. Sort by prive" << std::endl;
	std::cout << "9. Sort by name" << std::endl;
	std::cout << "10. Sort by name and producer" << std::endl;
	std::cout << "11. Search product" << std::endl;
	std::cout << "12. Add in list" << std::endl;
	std::cout << "13. Clear the list" << std::endl;
	std::cout << "14. Generate a random list" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

void Ui::ui_data(Ui& ui)
{
	ui.service.addProduct("ball", "fotball", 150, "Intersport");
	ui.service.addProduct("bed", "big", 7000, "STW");
	ui.service.addProduct("bicycle", "MTB", 13000, "Bikesport");
	ui.service.addProduct("ball", "rugby", 300, "SportRugby");
}

void Ui::ui_printProducts()
{
	std::for_each(service.getAllS().begin(), service.getAllS().end(), [](Product p) 
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_addProduct(Ui& ui)
{
	std::string Name;
	std::string Type;
	std::string Producer;
	int Price;

	std::cout << "Add a product: " << std::endl;
	std::cout << "Name: "; std::cin >> Name;
	std::cout << "Type: "; std::cin >> Type;
	std::cout << "Price: "; std::cin >> Price;
	std::cout << "Producer: "; std::cin >> Producer;

	ui.service.addProduct(Name, Type, Price, Producer);
	std::cout << "Product added with succes !" << std::endl;
}

void Ui::ui_modifyProduct(Ui& ui)
{
	std::string NameI;
	std::string TypeI;
	std::string ProducerI;

	std::cout << "Modify a product:" << std::endl;
	std::cout << "Name: "; std::cin >> NameI;
	std::cout << "Type: "; std::cin >> TypeI;
	std::cout << "Producer: "; std::cin >> ProducerI;

	std::string Name;
	std::string Type;
	std::string Producer;
	int Price;

	std::cout << "Name: "; std::cin >> Name;
	std::cout << "Type: "; std::cin >> Type;
	std::cout << "Price: "; std::cin >> Price;
	std::cout << "Producer: "; std::cin >> Producer;

	ui.service.modifyProduct(NameI, TypeI, ProducerI, Name, Type, Price, Producer);
	std::cout << "Product modified with succes !" << std::endl;
}

void Ui::ui_removeProduct(Ui& ui)
{
	std::string Name;
	std::string Type;
	std::string Producer;
	int Price;

	std::cout << "Remove a product: " << std::endl;
	std::cout << "Name: "; std::cin >> Name;
	std::cout << "Type: "; std::cin >> Type;
	std::cout << "Price: "; std::cin >> Price;
	std::cout << "Producer: "; std::cin >> Producer;

	ui.service.removeProduct(Name, Type, Price, Producer);
	std::cout << "Product removed with succes!" << std::endl;
}

void Ui::ui_filterPrice(Ui& ui)
{
	int Price;

	std::cout << "Enter a price: ";
	std::cin >> Price;

	std::vector<Product> vector = ui.service.filterPrice(Price);
	std::for_each(vector.begin(), vector.end(), [](Product p) 
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_filterName(Ui& ui)
{
	std::string Name;

	std::cout << "Enter a name: ";
	std::cin >> Name;

	std::vector<Product> vector = ui.service.filterName(Name);
	std::for_each(vector.begin(), vector.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_filterProducer(Ui& ui)
{
	std::string Producer;

	std::cout << "Enter a producer: ";
	std::cin >> Producer;

	std::vector<Product> vector = ui.service.filterProducer(Producer);
	std::for_each(vector.begin(), vector.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_sortByPrice(Ui& ui)
{
	int optiune;

	std::cout << "0. Descending 1. Ascending: ";
	std::cin>> optiune;
	
	std::vector<Product> vec;
	if (optiune == 1)
		vec = ui.service.smallerPrice();
	if (optiune == 0)
		vec = ui.service.biggerPrice();
	std::for_each(vec.begin(), vec.end(), [](Product p) 
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_sortByName(Ui& ui)
{
	int optiune;

	std::cout << "0. Descending 1. Ascending: ";
	std::cin >> optiune;

	std::vector<Product> vec;
	if (optiune == 1)
		vec = ui.service.smallerName();
	if (optiune == 0)
		vec = ui.service.biggerName();
	std::for_each(vec.begin(), vec.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_sortByType(Ui& ui)
{
	int optiune;

	std::cout << "0. Descending 1. Ascending: ";
	std::cin >> optiune;

	std::vector<Product> vec;
	if (optiune == 1)
		vec = ui.service.smallerType();
	if (optiune == 0)
		vec = ui.service.biggerType();
	std::for_each(vec.begin(), vec.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_searchProduct(Ui & ui)
{
	std::string Name;
	std::string Type;
	std::string Producer;
	int Price;

	std::cout << "Search product: " << std::endl;
	std::cout << "Name: "; std::cin >> Name;
	std::cout << "Type: ";  std::cin >> Type;
	std::cout << "Price: "; std::cin >> Price;
	std::cout << "Producer: "; std::cin >> Producer;

	std::vector<Product> vec = ui.service.searchProduct(Name, Type, Price, Producer);
	std::for_each(vec.begin(), vec.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}

void Ui::ui_addList(Ui & ui, std::vector<Product>& cos)
{
	std::string Name;
	int Price = 0;

	std::cout << "Enter a product by name: ";
	std::cin >> Name;
	ui.service.addListService(cos, Name);
		
	std::for_each(cos.begin(), cos.end(), [&Price](Product p)
	{Price += p.getPrice(); std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << " " << std::endl << "Price total: " << Price << std::endl; });
}

void Ui::ui_clearList(Ui & ui, std::vector<Product>& cos)
{
	std::cout << "The list will be cleared after this ." << std::endl;

	ui.service.clearListService(cos);
}

void Ui::ui_generateList(Ui & ui, std::vector<Product>& cos)
{
	int nrProduct=0;
	std::cout << "Generate a random list with products: " << std::endl;

	std::mt19937 mt(std::random_device{}());
	const std::uniform_int_distribution<> dist(1, 20);
	int nr = dist(mt);

	while (nr) {
		std::mt19937 mt2(std::random_device{}());
		const std::uniform_int_distribution<> dist2(1,ui.service.getSize()-1);
		nrProduct = dist2(mt2);
		ui.service.generateList(cos, nrProduct);
		nr -= 1;
	}
	
	std::for_each(cos.begin(), cos.end(), [](Product p)
	{std::cout << "Name: " << p.getName() << " Type: " << p.getType() << " Price: " << p.getPrice() << " Producer: " << p.getProducer() << std::endl; });
}


int main() {
	{
		int option = 1, verif = 0;

		Teste t;
		t.tests();

		RepositoryProduct repo = RepositoryProduct();
		ServiceProduct service = ServiceProduct(repo);
		Ui ui = Ui(service);

		ui.ui_data(ui);

		std::vector<Product> cos;

		while (1) {
			ui.ui_menu();
			std::cin >> option;
			try {
				switch (option) {
				case 0:
					verif = 1;
					break;
				case 1:
					ui.ui_printProducts();
					break;
				case 2:
					ui.ui_addProduct(ui);
					break;
				case 3:
					ui.ui_modifyProduct(ui);
					break;
				case 4:
					ui.ui_removeProduct(ui);
					break;
				case 5:
					ui.ui_filterPrice(ui);
					break;
				case 6:
					ui.ui_filterName(ui);
					break;
				case 7:
					ui.ui_filterProducer(ui);
					break;
				case 8:
					ui.ui_sortByPrice(ui);
					break;
				case 9:
					ui.ui_sortByName(ui);
					break;
				case 10:
					ui.ui_sortByType(ui);
					break;
				case 11:
					ui.ui_searchProduct(ui);
					break;
				case 12:
					ui.ui_addList(ui,cos);
					break;
				case 13:
					ui.ui_clearList(ui, cos);
					break;
				case 14:
					ui.ui_generateList(ui, cos);
					break;
				default:
					break;
				}
				if (verif == 1)
					break;
				std::cout << std::endl;
			}
			catch (ValidatorException& val) {
				std::cout << val.getMessage() << std::endl;
			}
			catch (RepositoryException& rep) {
				std::cout << rep.getMessage() << std::endl;
			}
			
		}
	}

	_CrtDumpMemoryLeaks();

	return 0;
}
