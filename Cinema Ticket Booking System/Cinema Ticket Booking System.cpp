// Cinema Ticket Booking System.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

//functions
string getUserName();
int getNumOfTickets();
void displayMenu();
int verifySelection(int selection);
double getTicketPrice(int ticketType);
double calcTotalCost(int numTickets);
double calcDiscount(double totalCost, int numTickets);
void displayResults(string name, double totalCost, double discount);

int main()
{
	string userName;
	int numTickets;
	double totalCost;
	double discount;

	userName = getUserName();
	numTickets = getNumOfTickets();

	totalCost = calcTotalCost(numTickets);
	discount = calcDiscount(totalCost, numTickets);

	displayResults(userName, totalCost, discount);

	return 0;
}

//function to acquire the users full name
string getUserName()
{
	string name;

	cout << "Please enter your full name: ";
	getline(cin, name);

	return name;
}

//function to get data and verify the number of tickets
int getNumOfTickets()
{
	int tickets;

	cout << "Enter number of tickets: ";
	cin >> tickets;

	while (tickets <= 0)
	{
		cout << "Invalid number of tickets. Try again: ";
		cin >> tickets;
	}

	return tickets;
}

//function to display the menu
void displayMenu()
{
	cout << "\n---Ticket Menu---" << endl;
	cout << "1. Standard Ticket - R80" << endl;
	cout << "2. 3D Movie Ticket - R120" << endl;
	cout << "3. IMAX Ticket - R150" << endl;
	cout << "4. VIP Lounge Ticket - R200" << endl;
}

//function to verify ticket selection
int verifySelection(int selection)
{
	while (selection < 1 || selection > 4)
	{
		cout << "Invalid selection. Enter a value between 1 and 4: ";
		cin >> selection;
	}

	return selection;
}

//function to return the ticket price
double getTicketPrice(int ticketType)
{
	switch (ticketType)
	{
		case 1:
			return 80.0;
		case 2:
			return 120.0;
		case 3: 
			return 150.0;
		case 4:
			return 200.0;
		default:
			return 0.0;
	}
}

//function to select the ticket type as well as calculating the total
double calcTotalCost(int numTickets)
{
	double total = 0;
	int ticketType;

	for (int i = 1; i <= numTickets; i++)
	{
		displayMenu();

		cout << "Select the Type of ticket you would like "
			<< i << ": ";
		cin >> ticketType;

		ticketType = verifySelection(ticketType);

		total = total + getTicketPrice(ticketType);
	}

	return total;
}

//function to dtermine the discount
double calcDiscount(double totalCost, int numTickets)
{
	double discount = 0;

	if (numTickets >= 5 && totalCost > 600)
	{
		discount = totalCost * 0.12;
	}

	return discount;
}

//Function to display the final results
void displayResults(string name, double totalCost, double discount)
{
	double finalAmmount = totalCost - discount;

	cout << "\n--- Booking Summary ---" << endl;
	cout << "Customer name: " << name << endl;
	cout << fixed << setprecision(2);
	cout << "Total Cost: R" << totalCost << endl;
	cout << "Discount applied: R" << discount << endl;
	cout << "Final Ammount due: R" << finalAmmount << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
