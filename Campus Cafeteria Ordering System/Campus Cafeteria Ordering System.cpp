// Scenario: Campus Cafeteria Ordering System

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


int main()
{
    string name, surname;

    //student name & surname
    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your surname ";
    cin >> surname;

    //Menu
    string items[8] =
    {
        "Chicken Burger",
        "Beef Burger",
        "Veggie Wrap",
        "French Fries",
        "Soft Drink",
        "Milkshake",
        "Pizza Slice",
        "Salad Bowl",
    };

    double prices[8] =
    {
        85.00,
        95.00,
        70.00,
        40.00,
        25.00,
        45.00,
        60.00,
        75.00,
    };

    cout << "\n===== Cafeteria Menu =====\n";

    for (int i = 0; i < 8; i++)
    {
        cout << i + 1 << ". "
            << items[i]
            << " - R"
            << fixed << setprecision(2)
            << prices[i] << endl;
    }

    int numOfItems;

    cout << "\nHow many items would you like to order (max 10): ";
    cin >> numOfItems;

    while (numOfItems < 1 || numOfItems > 10)
    {
        cout << "Invalid number. Enter a value between 1 and 10: ";
        cin >> numOfItems;
    }

    double total = 0;

    for (int i = 1; i <= numOfItems; i++)
    {
        int itemNum;
        int quantity;

        cout << "\nEnter item number (1-8): ";
        cin >> itemNum;

        while (itemNum < 1 || itemNum>8)
        {
            cout << "Invalid item number. Enter a number between 1 & 8: ";
            cin >> itemNum;
        }

        cout << "Enter Quantity: ";
        cin >> quantity;

        while (quantity <= 0)
        {
            cout << "Invalid quantity. Enter a positive number: ";
            cin >> quantity;
        }

        total = total + (prices[itemNum - 1] * quantity);
    }

    double discount = 0;

    if (total > 300)
    {
        discount = total * 0.05;
    }

    double finalAmmount = total - discount;

    cout << "\n=========================\n";
    cout << "Total: R" << fixed << setprecision(2) << total << endl;
    cout << "Discount: R" << discount << endl;
    cout << "Final Amount: R" << finalAmmount << endl;

    return 0;
}

