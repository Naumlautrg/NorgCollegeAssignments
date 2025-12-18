/*
* 
*	Uses "Adult" dataset sourced from https://archive.ics.uci.edu/dataset/2/adult
*	Purpose of data: Predict whether annual income of an individual exceeds $50K/yr based on census data. Also known as "Census Income" dataset.
* 
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#include "adultincome.h"

std::vector<std::string> splitRecord_withStringStream(const std::string& record, char delimiter)
{
	std::vector<std::string> fields;
	std::stringstream ss(record);
	std::string field;

	while (std::getline(ss, field, delimiter))
	{
		fields.push_back(field);
	}

	return fields;
}

double getAverageAge(const std::vector<AdultIncome>& records)
{
	double sum = 0.0;
	for (const auto& currentRecord : records)
	{
		sum += currentRecord.age;
	}

	return sum / records.size();
}

int getIncomeOver50kNum(const std::vector<AdultIncome>& records)
{
	int incomeOver50k = 0;
	for (const auto& currentRecord : records)
	{
		if (currentRecord.incomeOver50k == " >50K")
			incomeOver50k += 1;
	}

	return incomeOver50k;
}

int main()
{
	std::cout << std::fixed << std::setprecision(0);
	
	std::ifstream inputFile("adult.data");
	
	if (!inputFile)
	{
		std::cout << "ERROR: File not found.\n";
		return -1;
	}

	std::string currentLine;

	std::vector<AdultIncome> records;

	std::cout << "NOTE: This dataset has been truncated to 500 rows (down from 32561 rows).\n";
	std::cout << "Data entries with a \"?\" are missing data values.\n";
	std::cout << "View console in fullscreen to analyze output properly.\n\n\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Age     Working Class     Final Weight     Education     Education Num     Marital Status     Occupation     Relationship     Race     Sex     Capital Gain     Capital Loss     Hours Per Week     Native Country     Income\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";

	while (std::getline(inputFile, currentLine))
	{
		// Delimiter for our dataset is a comma
		auto splitRecord = splitRecord_withStringStream(currentLine, ',');

		if (splitRecord.size() != 15)
		{
			std::cout << "ERROR: Unexpected number of fields (15 expected).";
			continue;
		}

		// Format output as spreadsheet
		std::cout << std::setw(2) << splitRecord[0];
		std::cout << std::setw(18) << splitRecord[1];
		std::cout << std::setw(15) << splitRecord[2];
		std::cout << std::setw(17) << splitRecord[3];
		std::cout << std::setw(12) << splitRecord[4];
		std::cout << std::setw(24) << splitRecord[5];
		std::cout << std::setw(18) << splitRecord[6];
		std::cout << std::setw(16) << splitRecord[7];
		std::cout << std::setw(9) << splitRecord[8];
		std::cout << std::setw(8) << splitRecord[9];
		std::cout << std::setw(12) << splitRecord[10];
		std::cout << std::setw(16) << splitRecord[11];
		std::cout << std::setw(18) << splitRecord[12];
		std::cout << std::setw(24) << splitRecord[13];
		std::cout << std::setw(12) << splitRecord[14];
		std::cout << "\n\n\n";
		AdultIncome currentRecord =
		{
			std::stoi(splitRecord[0]),
			splitRecord[1],
			std::stoi(splitRecord[2]),
			splitRecord[3],
			std::stoi(splitRecord[4]),
			splitRecord[5],
			splitRecord[6],
			splitRecord[7],
			splitRecord[8],
			splitRecord[9],
			std::stoi(splitRecord[10]),
			std::stoi(splitRecord[11]),
			std::stoi(splitRecord[12]),
			splitRecord[13],
			splitRecord[14]
		};

		records.push_back(currentRecord);
	}
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(112) << "RESULTS" << "\n";
	std::cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n";
	std::cout << "The average age of adults is " << getAverageAge(records) << "\n";
	std::cout << "The number of adults with over 50k annual income is " << getIncomeOver50kNum(records) << "\n\n";
	return 0;
}