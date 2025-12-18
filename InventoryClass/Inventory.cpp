#include "Inventory.h"

Inventory::Inventory()
{
	itemName = "TBD";
	itemPrice = 0.00;
	unitsAvailable = 0;
}

Inventory::Inventory(std::string name, double price, int units)
{
	itemName = name;
	itemPrice = price;
	unitsAvailable = units;
}

void Inventory::setItemName(std::string name)
{
	itemName = name;
}

void Inventory::setItemPrice(double price)
{
	itemPrice = 0.00;
}

void Inventory::setUnitsAvailable(int units)
{
	unitsAvailable = 0;
}

std::string Inventory::getItemName()
{
	return itemName;
}

double Inventory::getItemPrice()
{
	return itemPrice;
}

int Inventory::getUnitsAvailable()
{
	return unitsAvailable;
}

double Inventory::calculateTotalValue()
{
	return itemPrice * unitsAvailable;
}