#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

struct Supermarket
{
    string name;              // Name of the supermarket
    string storeHours;        // Store operating hours
    int numEmployees;         // Number of employees at the supermarket
    double employeeSalaries;  // Pay rate per employee
    double loyaltyFee;        // Fee for loyalty membership
    double budget;            // Total store operating funds
};

struct Item
{
    double wholesalePrice; // Supermarket's cost
    double regularPrice;   // Price for regular customers
    double memberPrice;    // Price for store members
};

int main()
{
    const string BREAK_MESSAGE = "=============================\n";
    const double SALES_TAX_RATE = 0.07;
    string employeePassword = "csmart";

    cout << fixed << setprecision(2);
    cout << "Starting supermarket simulation\n" << endl;

    ifstream inFS;

    string fileName;
    cin >> fileName >> endl;

    //****How can we repeat this process until a valid filename is used? ******
    if (fileName == "supermarket.txt") {
        cout << "Processing supermarket.txt" << endl;
    }
    else if (fileName = "exit") {
        cout << "Exiting simulation early" << endl;
    }
    else {
        cout << "Please enter a valid file path" << endl;
    }

    inFS.open(fileName);

    //ensure file is open.
    if(!inFS.is_open()) {
        cout << "Could not open file " << filename << ".txt" << endl;
        return 1
    }

    //Start of the menu kiosk.... need to impliment the loop. 
    cout << "Menu \n" << BREAK_MESSAGE << "1. Display Supermarket Information" << endl;
    cout << "2. Display Aisles information \n" << "3. Checkout \n" << endl;
    cout << "4. Access Employee Menu \n" << "-1. Exit program \n" << endl;
    cout << BREAK_MESSAGE << endl << "Enter choice: " << endl;

    // Initialize store and inventory items
    Supermarket myMarket;
    Item frozenPizza = {3.75, 5.99, 5.49};  // Aisle 1: Frozen Foods
    Item chips = {1.85, 3.49, 2.99};        // Aisle 2: Snacks
    Item bleach = {2.10, 3.79, 3.29};       // Aisle 3: Cleaning Supplies
    Item shampoo = {4.20, 6.99, 6.49};      // Aisle 4: Health & Beauty
    Item iceCream = {2.95, 4.79, 4.29};     // Aisle 1: Frozen Foods

    cout << "\nFinished simulation" << endl;
    return 0;
}
