#include <iostream>
#include <limits>
#include "GroceryTracker.h"

using namespace std;

int main() {

	GroceryTracker grocery;
	int menuChoice = 0;

	//Read input from file 
	grocery.ReadFile();

	//Create backup file automatically
	grocery.CreateBackupFile();

	while (menuChoice != 4) {

		cout << endl;
		cout << "==============================" << endl;
		cout << "      CORNER GROCER MENU      " << endl;
		cout << "==============================" << endl;
		cout << "1. Search for an item" << endl;
		cout << "2. Display item frequencies" << endl;
		cout << "3. Display histogram" << endl;
		cout << "4. Exit program" << endl;
		cout << "Enter your choice: ";

		cin >> menuChoice;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "Invalid input. Enter a number from 1 to 4." << endl;
			menuChoice = 0;
			continue;
		}

		switch (menuChoice) {

		case 1:
			grocery.SearchItem();
			break;

		case 2:
			grocery.PrintAllItems();
			break;

		case 3:
			grocery.PrintHistogram();
			break;

		case 4:
			cout << "Thank you for using the Corner Grocer program." << endl;
			break;

		default:
			cout << "Invalid option. Please select 1 through 4." << endl;
			break;

		}
	}
	return 0;
}

