/*
 * Pelican.cpp
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class Pelican derived from the class Oviparous.
 *
 */

#include "Pelican.h"

// Default constructor
Pelican::Pelican() {
}

// Returns a string with all of the animal's information in the same format it is in in the file
string Pelican::toString() {
	// Print Oviparous' data with this class' data concatenated to it
	return Oviparous::toString() + "Pelican" + padString(SUB_LENGTH - 7) + to_string(NumberOfEggs) + " 0";
} // End toString

// Print the animal's information to the screen
void Pelican::print() {
	// Print Oviparous' data
	Oviparous::print();
	// Print type with padding, number of eggs with padding, and nursing status with padding
	cout << setw(SUB_LENGTH + PADDING) << setfill(' ') << type << setw(INT_LENGTH + PADDING) << NumberOfEggs << setw(INT_LENGTH + PADDING) << 0;
} // End print
