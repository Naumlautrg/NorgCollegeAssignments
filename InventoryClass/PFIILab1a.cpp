#include "Inventory.h"
#include <iomanip>

int main()
{
	Inventory item1;
	Inventory item2("Coffee", 3.50, 11);

	// Format decimal output down to the nearest cent
	std::cout << std::fixed << std::setprecision(2);

	// Display Item 1 values
	std::cout << "Item 1 Values\n";
	std::cout << "---------------------------\n";
	std::cout << "Item 1 Name: " << item1.getItemName() << "\n";
	std::cout << "Item 1 Price: $" << item1.getItemPrice() << "\n";
	std::cout << "Item 1 Units Available: " << item1.getUnitsAvailable() << "\n";
	std::cout << "---------------------------\n\n";

	// Display Item 2 values
	std::cout << "Item 2 Values\n";
	std::cout << "---------------------------\n";
	std::cout << "Item 2 Name: " << item2.getItemName() << "\n";
	std::cout << "Item 2 Price: $" << item2.getItemPrice() << "\n";
	std::cout << "Item 2 Units Available: " << item2.getUnitsAvailable() << "\n";
	std::cout << "---------------------------\n\n";

	// Calculate total value for both objects
	double item1TotalValue = item1.calculateTotalValue();
	double item2TotalValue = item2.calculateTotalValue();

	// Display total values
	std::cout << "Item 1 Total Value: $" << item1TotalValue << "\n";
	std::cout << "Item 2 Total Value: $" << item2TotalValue << "\n";
}