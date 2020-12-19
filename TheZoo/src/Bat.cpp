/*
 * Bat.cpp
 *
  *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class Bat derived from the class Mamma.
 *
 */

#include "Bat.h"

// Default constructor
Bat::Bat() {
}

// Returns a string with all of the animal's information in the same format it is in in the file
string Bat::toString() {
	// Returns Mammal's toString with "Bat", padding, number of eggs with a trailing space, and nursing status
	return Mammal::toString() + "Bat" + padString(SUB_LENGTH - 3) + "0 " + to_string(Nurse);
} // End toString

// Print the animal's information to the screen
void Bat::print() {
	// Print Mammal's data
	Mammal::print();
	// Print type with padding, number of eggs with padding, and nursing status with padding
	cout << setw(SUB_LENGTH + PADDING) << setfill(' ') << type << setw(INT_LENGTH + PADDING) << 0 << setw(INT_LENGTH + PADDING) << Nurse;
} // End print
