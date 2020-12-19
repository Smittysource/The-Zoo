/*
 * SeaLion.cpp
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class SeaLion derived from the class Mammal.
 *
 */

#include "SeaLion.h"

// Default constructor
SeaLion::SeaLion() {
}

// Returns a string with all of the animal's information in the same format it is in in the file
string SeaLion::toString() {
	// Returns Mammal's toString with "SeaLion", padding, number of eggs with a trailing space, and nursing status
	return Mammal::toString() + "SeaLion" + padString(SUB_LENGTH - 7) + "0 " + to_string(Nurse);
} // End toString

// Print the animal's information to the screen
void SeaLion::print() {
	// Print Mammal's data
	Mammal::print();
	// Print type with padding, number of eggs with padding, and nursing status with padding
	cout << setw(SUB_LENGTH + PADDING) << setfill(' ') << type << setw(INT_LENGTH + PADDING) << 0 << setw(INT_LENGTH + PADDING) << Nurse;
}  // End print
