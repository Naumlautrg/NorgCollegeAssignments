#include <iostream>

class Inventory
{
public:
	// Constructors
	Inventory();
	Inventory(std::string name, double price, int units);

	// Setters
	void setItemName(std::string name);
	void setItemPrice(double price);
	void setUnitsAvailable(int units);

	// Getters
	std::string getItemName();
	double getItemPrice();
	int getUnitsAvailable();

	// Methods
	double calculateTotalValue();

private:
	// Member Variables
	std::string itemName;
	double itemPrice;
	int unitsAvailable;
};

