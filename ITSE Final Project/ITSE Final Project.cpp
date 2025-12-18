/*
* AIRLINE RESERVATION PROJECT
* 
*/

#include <iostream>
#include <iomanip>
#include <string>

// Constant Declarations
const int FLIGHT_DAILYCOUNT = 8;
const int SEATING_ROWS = 4;
const int SEATING_COLUMNS = 16;

// Function Prototypes
// - Display
void displayWelcomeMessage();
void displayInputCommand(char&);
void displayCommands();
void displayErrorMessage();
void displayEndMessage();
void displayPassengerList(int flightIndex);
void displayFlightSchedule();
void displaySeatingChart(int flightIndex);

// - Reservations
void bookReservation(int flightIndex);
void cancelReservation(int flightIndex);

// - Get
int getFlightIndex();

// Array Variable Declarations
// - 1D
int flightNumbers[FLIGHT_DAILYCOUNT] = { 3548, 3488, 3498, 3644, 3487, 3497, 3645, 3549 };
char seats[SEATING_ROWS] = { 'A', 'B', 'C', 'D' };

// - 3D
int seatingChart[FLIGHT_DAILYCOUNT][SEATING_COLUMNS][SEATING_ROWS] = {0};
std::string lastName[FLIGHT_DAILYCOUNT][SEATING_COLUMNS][SEATING_ROWS] = {""};
std::string firstName[FLIGHT_DAILYCOUNT][SEATING_COLUMNS][SEATING_ROWS] = {""};


int main()
{
	int flightIndex = 0;
	char command = ' ';

	displayWelcomeMessage();
	system("cls");
	displayCommands();

	do
	{
		displayInputCommand(command);
		
		switch (toupper(command))
		{
		// Command - Display Flight Schedule
		case 'S':
			displayFlightSchedule();
			break;
		// Command - Display Seating Chart
		case 'D':
			displayFlightSchedule();
			flightIndex = getFlightIndex();
			displaySeatingChart(flightIndex);
			break;
		// Command - Book a Reservation
		case 'B':
			displayFlightSchedule();
			flightIndex = getFlightIndex();
			bookReservation(flightIndex);
			break;
		// Command - Cancel a Reservation
		case 'C':
			displayFlightSchedule();
			flightIndex = getFlightIndex();
			cancelReservation(flightIndex);
			break;
		// Command - Display Passenger List
		case 'V':
			displayFlightSchedule();
			flightIndex = getFlightIndex();
			displayPassengerList(flightIndex);
			break;
		// Command - Display Menu Commands
		case 'L':
			displayCommands();
			break;
		// Command - Exit the Program
		case 'Q':
			break;
		// Command - Incorrect Command Entered
		default:
			displayErrorMessage();
			break;
		}
	} while (command != 'Q');

	displayEndMessage();

	system("pause");

	return 0;
}

// Function Defintitions Below
// - Display

void displayWelcomeMessage()
{
	std::cout << "************************************************\n";
	std::cout << "*                 Welcome                      *\n";
	std::cout << "*                   to                         *\n";
	std::cout << "*             Tyler Eagle Jet                  *\n";
	std::cout << "*            Reservation System                *\n";
	std::cout << "*                                              *\n";
	std::cout << "*              8 Flights Daily                 *\n";
	std::cout << "*                  between                     *\n";
	std::cout << "*           Tyler Pounds Field (TYR)           *\n";
	std::cout << "*                   and                        *\n";
	std::cout << "*           Dallas/Fort Worth (DFW)            *\n";
	std::cout << "*                                              *\n";
	std::cout << "************************************************\n";

	system("pause");
}

void displayInputCommand(char& c)
{
	std::cout << "\nEnter command (Press L to return to the menu): ";

	std::cin >> c;
	c = toupper(c);

	system("cls");
}

void displayCommands()
{
	std::cout << "************************************************\n";
	std::cout << "*                                              *\n";
	std::cout << "* (S)how flight schedules                      *\n";
	std::cout << "* (B)ook a reservation                         *\n";
	std::cout << "* (C)ancel a reservation                       *\n";
	std::cout << "* (D)isplay seating chart                      *\n";
	std::cout << "* (V)iew passenger list                        *\n";
	std::cout << "* (L)ist commands                              *\n";
	std::cout << "* (Q)uit                                       *\n";
	std::cout << "*                                              *\n";
	std::cout << "************************************************\n";
}

void displayErrorMessage()
{
	std::cout << "\n==>Error: Command not recognized!\n";
	std::cout << "\n\n";
}

void displayEndMessage()
{
	system("cls");
	std::cout << "\n\n\n\n";
	std::cout << "THANKS FOR USING OUR FLIGHT SYSTEM";
	std::cout << "\nCOME VISIT US AGAIN!\n";
	std::cout << "\n\n\n\n";
}

void displayPassengerList(int flightIndex)
{
	int passengerNum = 0;

	for (int i = 0; i < SEATING_COLUMNS; i++)
	{
		for (int j = 0; j < SEATING_ROWS; j++)
		{
			if (seatingChart[flightIndex][i][j] == 1)
			{
				passengerNum += 1;

				std::cout << "Seat: " << std::setw(5) << i << seats[j];
				std::cout << "\t" << firstName[flightIndex][i][j] << " " << lastName[flightIndex][i][j];
				std::cout << "\n";
			}
		}
	}

	std::cout << "\nNumber of passengers: " << passengerNum << "\n\n";
}

void displayFlightSchedule()
{
	std::cout << "************************************************\n";
	std::cout << "* Tyler Pounds Field (TYR)                     *\n";
	std::cout << "*                                              *\n";
	std::cout << "* Flight no.    Depart TYR/Arrive DFW          *\n";
	std::cout << "*                                              *\n";
	std::cout << "*    3548          06:30am/07:15am             *\n";
	std::cout << "*    3488          10:55am/11:40am             *\n";
	std::cout << "*    3498          04:25pm/05:10pm             *\n";
	std::cout << "*    3644          05:50pm/05:35pm             *\n";
	std::cout << "*                                              *\n";
	std::cout << "* Dallas/Fort Worth (DFW)                      *\n";
	std::cout << "*                                              *\n";
	std::cout << "* Flight no.    Depart TYR/Arrive DFW          *\n";
	std::cout << "*                                              *\n";
	std::cout << "*    3487          09:45am/10:30am             *\n";
	std::cout << "*    3497          03:15pm/4:00pm              *\n";
	std::cout << "*    3645          04:40pm/5:25pm              *\n";
	std::cout << "*    3549          08:10pm/8:55pm              *\n";
	std::cout << "*                                              *\n";
	std::cout << "*                                              *\n";
	std::cout << "************************************************\n\n";
}

void displaySeatingChart(int flightIndex)
{
	std::cout << "\n";
	for (int i = 0; i < SEATING_COLUMNS; i++)
	{
		for (int j = 0; j < SEATING_ROWS; j++)
		{
			// Concatenate the elements of the seat label for formatted display with setw()
			std::string seatLabel = 
				seatingChart[flightIndex][i][j] == 1
				? std::string("(" + std::to_string(i + 1) + seats[j] + ")") // Seat occupied
				: " " + std::to_string(i + 1) + seats[j] + " "; // Seat empty

			if (j == 2)
				std::cout << "\t";

			// Space the rows evenly
			std::cout << std::setw(6);

			std::cout << seatLabel;
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

// - Reservations
void bookReservation(int flightIndex)
{
	int seatNumber = 0;
	std::string seatfirstName;
	std::string seatLastName;
	char seatRow = ' ';
	bool seatExists = false;
	
	while (!seatExists)
	{
		std::cout << "Enter Seat Preference: ";
		std::cin >> seatNumber;
		std::cin >> seatRow;

		seatRow = toupper(seatRow);

		// Check if seat exists
		if (seatNumber <= SEATING_COLUMNS && seatNumber >= 1 &&
			(seatRow == 'A' || seatRow == 'B' || seatRow == 'C' || seatRow == 'D'))
			seatExists = true;

		if (!seatExists)
		{
			std::cout << "Seat " << seatNumber << seatRow << " does not exist. Please try again.\n\n";
		}
	}

	int seatRowIndex = 0;
	for (int i = 0; i < SEATING_ROWS; i++)
	{
		if (seatRow == seats[i])
			seatRowIndex = i;
	}

	system("cls");

	std::cout << "Enter First Name: ";
	std::cin >> seatfirstName;

	std::cout << "Enter Last Name: ";
	std::cin >> seatLastName;

	std::cout << "\n";

	std::cout << "Passenger: " << seatfirstName << " " << seatLastName << "\n";
	std::cout << "Booked on Flight: " << flightNumbers[flightIndex] << "\n";
	std::cout << "Seat: " << seatNumber << seatRow << "\n";

	firstName[flightIndex][seatNumber - 1][seatRowIndex] = seatfirstName;
	lastName[flightIndex][seatNumber - 1][seatRowIndex] = seatLastName;
	seatingChart[flightIndex][seatNumber - 1][seatRowIndex] = 1;
}

void cancelReservation(int flightIndex)
{
	int seatNumber = 0;
	char seatRow = ' ';
	bool seatExists = false;

	displaySeatingChart(flightIndex);

	while (!seatExists)
	{
		std::cout << "Enter Seat to Cancel: ";
		std::cin >> seatNumber;
		std::cin >> seatRow;

		seatRow = toupper(seatRow);

		// Check if seat exists
		if (seatNumber <= SEATING_COLUMNS && seatNumber >= 1 &&
			(seatRow == 'A' || seatRow == 'B' || seatRow == 'C' || seatRow == 'D'))
			seatExists = true;

		if (!seatExists)
		{
			std::cout << "Seat " << seatNumber << seatRow << " does not exist. Please try again.\n\n";
		}
	}
	int seatRowIndex = 0;
	for (int i = 0; i < SEATING_ROWS; i++)
	{
		if (seatRow == seats[i])
			seatRowIndex = i;
	}

	system("cls");

	std::cout << "\n";

	std::cout << "Passenger: " << firstName[flightIndex][seatNumber - 1][seatRowIndex] << " " << lastName[flightIndex][seatNumber - 1][seatRowIndex] << "\n";
	std::cout << "Flight Canceled: " << flightNumbers[flightIndex] << "\n";
	std::cout << "Seat: " << seatNumber << seatRow << "\n";

	firstName[flightIndex][seatNumber - 1][seatRowIndex] = "";
	lastName[flightIndex][seatNumber - 1][seatRowIndex] = "";
	seatingChart[flightIndex][seatNumber - 1][seatRowIndex] = 0;
}


// - Get
int getFlightIndex()
{
	int flightNumber = 0;
	int flightIndex = -1;

	std::cout << "Please enter the flight number: ";

	std::cin >> flightNumber;

	while (flightIndex == -1)
	{
		for (int i = 0; i < FLIGHT_DAILYCOUNT; i++)
		{
			if (flightNumber == flightNumbers[i])
			{
				flightIndex = i;
			}
		}

		if (flightIndex == -1)
		{
			std::cout << "Invalid flight number. Please re-enter the flight number: ";
		}
	}

	system("cls");

	return flightIndex;
}
