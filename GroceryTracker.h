#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

class GroceryTracker {
public:
	GroceryTracker();

	void ReadFile();
	void CreateBackupFile();
	void SearchItem();
	void PrintAllItems();
	void PrintHistogram();

private:
	map<string, int> itemFrequency;
};

#endif
