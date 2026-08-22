#include "GroceryTracker.h"

//Constructor here
GroceryTracker::GroceryTracker() {
}

//Read the input file and counts each item

void GroceryTracker::ReadFile() {
	ifstream inputFile;
	string item;

	inputFile.open("CS210_Project_Three_Input_File.txt");

	if (!inputFile.is_open()) {
		cout << "Error opening input file." << endl;
		return;
	}

	while (inputFile >> item) {
		itemFrequency[item]++;
	}

	inputFile.close();
}

//Creates the backup file
void GroceryTracker::CreateBackupFile() {
	ofstream outputFile;

	outputFile.open("frequency.dat");

	if (!outputFile.is_open()) {
		cout << "Error creating backup file." << endl;
		return;
	}

	for (auto item : itemFrequency) {
		outputFile << item.first << " " << item.second << endl;
	}

	outputFile.close();
}

//Searche for an item and display how many times it was purchased 

void GroceryTracker::SearchItem() {
	string item;

	cout << "Enter the item you would like to search for: ";
	cin >> item;

	if (itemFrequency.find(item) != itemFrequency.end()) {
		cout << item << " was purchased " << itemFrequency[item] << " time(s)." << endl;
	}

	else {
		cout << item << " was purchased 0 times. " << endl;
	}
}

//Display all items and frequencies

void GroceryTracker::PrintAllItems() {
	cout << endl;
	cout << "Item Purchase Frequency" << endl; 
	cout << "-----------------------" << endl;

	for (auto item : itemFrequency) {
		cout << item.first << " " << item.second << endl;
	}

}

//Display the items as histogram

void GroceryTracker::PrintHistogram() {
	cout << endl;
	cout << "Purchase Frequency Histogram" << endl;
	cout << "----------------------------" << endl;

	for (auto item : itemFrequency) {
		cout << item.first << " ";

		for (int i = 0; i < item.second; ++i) {
			cout << "*";
		}

		cout << endl;
	}

}



