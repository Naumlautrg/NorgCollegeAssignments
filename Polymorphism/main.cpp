#include <iostream>
#include <iomanip>
#include <string>

class Computer
{
public:
	Computer()
	{
		cpuName = "";
		teraFLOPS = 0.00;
	}
	Computer(std::string pCpuName, double pTeraFLOPS)
	{
		cpuName = pCpuName;
		teraFLOPS = pTeraFLOPS;
	}
	std::string getCpuName()
	{
		return cpuName;
	}
	double getTeraFLOPS()
	{
		return teraFLOPS;
	}
protected:
	std::string cpuName;
	double teraFLOPS;
};

class PersonalComputer : public Computer
{
public:
	PersonalComputer()
	{
		monitorName = "";
	}
	PersonalComputer(std::string pCpuName, double pTeraFLOPS, std::string pMonitorName)
	{
		cpuName = pCpuName;
		teraFLOPS = pTeraFLOPS;
		monitorName = pMonitorName;
	}
	std::string getMonitorName()
	{
		return monitorName;
	}
protected:
	std::string monitorName;
};

class SmartPhone : public Computer
{
public:
	SmartPhone() 
	{ 
		batteryLife = 0.00; 
	}
	SmartPhone(std::string pCpuName, double pTeraFLOPS, double pBatteryLife)
	{
		cpuName = pCpuName;
		teraFLOPS = pTeraFLOPS;
		batteryLife = pBatteryLife;
	}
	double getBatteryLife()
	{
		return batteryLife;
	}
protected:
	double batteryLife;
};

class GameConsole : public Computer
{
public:
	GameConsole()
	{
		controllerCount = 0;
	}
	GameConsole(std::string pCpuName, double pTeraFLOPS, int pControllerCount)
	{
		cpuName = pCpuName;
		teraFLOPS = pTeraFLOPS;
		controllerCount = pControllerCount;
	}
	int getControllerCount()
	{
		return controllerCount;
	}
protected:
	int controllerCount;
};

int main()
{
	std::cout << std::fixed << std::setprecision(2);

	// Create objects
	Computer regularComputer("Generic weak CPU", 10.5);
	PersonalComputer personalComputer("Generic average CPU", 11.23, "Generic computer monitor");
	SmartPhone smartPhone("Generic above-average CPU", 5, 100.0);
	GameConsole gameConsole("Generic strong CPU", 9, 3);

	// Output
	std::cout << "Regular Computer: "
		<< "\nCPU - " << regularComputer.getCpuName()
		<< "\nTeraFLOPS - " << regularComputer.getTeraFLOPS() << "\n\n";

	std::cout << "Personal Computer: "
		<< "\nCPU - " << personalComputer.getCpuName()
		<< "\nTeraFLOPS - " << personalComputer.getTeraFLOPS()
		<< "\nMonitor Name - " << personalComputer.getMonitorName() << "\n\n";

	std::cout << "Smart Phone: "
		<< "\nCPU - " << smartPhone.getCpuName()
		<< "\nTeraFLOPS - " << smartPhone.getTeraFLOPS()
		<< "\nBattery Life - " << smartPhone.getBatteryLife() << "\n\n";

	std::cout << "Game Console: "
		<< "\nCPU - " << gameConsole.getCpuName()
		<< "\nTeraFLOPS - " << gameConsole.getTeraFLOPS()
		<< "\nController Count - " << gameConsole.getControllerCount() << "\n\n";
}