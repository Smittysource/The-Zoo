/*
 *  Animal.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Animal. This class contains pure virtual functions getNumberOfEggs, getNursing, setNumberOfEggs, and setNursing
 *  which must be defined in any derived classes. Therefore, an instance of Animal cannot be created.
 *
 */

#ifndef ANIMAL_H_
#define ANIMAL_H_
#include <string>				// Used to manipulate strings
#include <iostream>				// Used to output data to the screen through cout
#include <iomanip>				// Used to format data being output to screen


using namespace std;

class Animal {
public:
	// Declare member methods and fields
	Animal();													// Default constructor
	virtual ~Animal(){};										// Default destructor
	void setName(string Name);									// Mutator method to set the animal's name
	string getName();											// Accessor method to get the animal's name
	void setTrackNum(int TrackNum);								// Mutator method to set the animals Track#
	int getTrackNum();											// Accessor method to get the animals Track#
	virtual int getNumberOfEggs() = 0;							// Accessor for number of eggs. Derived classes must define this method
	virtual int getNursing() = 0;								// Accessor for nursing status. Derived classes must define this method
	virtual void setNumberOfEggs(int numEggs) = 0;				// Mutator for number of eggs. Derived classes must define this method
	virtual void setNursing(int nurse) = 0;						// Mutator for nursing status. Derived classes must define this method
	string padString(int paddingNeeded, char padChar = ' ');	// Utility method to add characters to a string for output
	virtual string toString();									// Returns a string with all of the animal's information in the same format it is in in the file
	virtual void print() {										// Print the animal's information to the screen
		cout << setw(PADDING) << "" << right << setw(TRACK_LENGTH) << setfill('0') << TrackNum << setfill(' ') << setw(PADDING) << "" << left << setw(NAME_LENGTH + PADDING) << Name;
	} // End print

	string Name;												// Name of animal as string
	int TrackNum;												// Track# of animal as int
	static const unsigned int TRACK_LENGTH = 6;					// Maximum allowed characters used for Track#
	static const int NAME_LENGTH = 15;							// Maximum allowed characters used for Name
	static const int TYPE_LENGTH = 15;							// Maximum allowed characters used for Type
	static const int SUB_LENGTH = 15;							// Maximum allowed characters used for Sub-type
	static const int PADDING = 4;								// Number of characters used for padding while printing to screen
	static const int INT_LENGTH = 5;							// Maximum allowed characters used for integers when printing to screen
}; // End Class Animal

#endif /* ANIMAL_H_ */
