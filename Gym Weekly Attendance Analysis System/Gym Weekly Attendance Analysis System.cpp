//Scenario: Gym Weekly Attendance Analysis System

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int attendance[7];
	int total = 0;
	int highest;
	int lowest;
	double average;

	cout << "Enter the number of members for each day: " << endl;

	for (int i = 0; i < 7; i++)
	{
		cout << "Day " << i + 1 << ": ";
		cin >> attendance[i];
	}

	highest = attendance[0];
	lowest = attendance[0];

	for (int i = 0; i < 7; i++)
	{
		total = total + attendance[i];

		if (attendance[i] > highest)
		{
			highest = attendance[i];
		}

		if (attendance[i] < lowest)
		{
			lowest = attendance[i];
		}
	}

	average = (double)total / 7;

	cout << fixed << setprecision(2);

	cout << "\nTotal Attendance: " << total << endl;
	cout << "Average Attendance: " << average << endl;
	cout << "Highest Attendance: " << highest << endl;
	cout << "Lowest Attendance: " << lowest << endl;

	if (average >= 80)
	{
		cout << "The gym had a BUSY week." << endl;
	}
	else
	{
		cout << "The gym had a SLOW week." << endl;
	}

	return 0;
}
