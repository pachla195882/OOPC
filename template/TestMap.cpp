#include "Map.h"														// Defines template Map<Key, Value>
#include <iostream>

using namespace std;

int main() {
	typedef unsigned int ID; 											// Identification number of Employee
	Map<ID, Employee> database;											// Database of employees
	database.add(761028073, Employee("Jan Kowalski", "salesman", 28)); 	// Add first employee: name: Jan Kowalski, position: salseman, age: 28,
	database.add(510212881, Employee("Adam Nowak", "storekeeper", 54));	// Add second employee: name: Adam Nowak, position: storekeeper, age: 54
	database.add(730505129, Employee("Anna Zaradna", "secretary", 32));	// Add third employee: name: Anna Zaradna, position: secretary, age: 32

	cout << database << endl;											// Print database

	Map<ID, Employee> newDatabase = database;							// Make a copy of database (copy constructor called)
	
	Employee* pE;
	pE = newDatabase.find(510212881);									// Find employee using its ID
	pE->position = "salesman";											// Modify the position of employee
	pE = newDatabase.find(761028073);									// Find employee using its ID
	pE->age = 29;														// Modify the age of employee

	database = newDatabase;												// Update original database (assignment operator called)
	
	cout << database << endl;											// Print original database




	typedef string BookTitle;
	Map<BookTitle, Book> library;
	library.add("Introduction to Electrodynamics", Book("David J. Griffiths", "education", 620, true));
	library.add("The Little Prince", Book("Antoine de Saint-Exupéry", "fable", 96, false));
	library.add("The 4-Hour Work Week", Book("Timothy Ferris", "self-help", 308, true));

	cout << library << endl;

	Book* book;
	if ( (book = library.find("The Little Prince") ) ) {
		book->lendBook();
		book->returnBook();
	}

	if ( (book = library.find("The 4-Hour Work Week") ) ) {
		book->lendBook();
	}

	cout << library << endl;
}
