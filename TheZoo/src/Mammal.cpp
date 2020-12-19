/*
 *  Mammal.cpp
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class Mammal derived from the class Animal.
 *
 */

#include "Mammal.h"

// Default constructor
Mammal::Mammal() {
	// Set nursing status to not nursing
	Nurse = 0;
} // End default constructor

// Default destructor
Mammal::~Mammal() {
} // End default destructor

// Returns a string with all of the mammal's information in the same format it is in in the file
string Mammal::toString() {
	// Return Animal's toString with Mammal concatenated to it
	return Animal::toString() + "Mammal" + padString(TYPE_LENGTH - 6);
} // End toString

// Print the animal's information to the screen
void Mammal::print() {
	// Print Animal's data
	Animal::print();
	// Print Mammal's data
	cout << setw(TYPE_LENGTH + PADDING) << setfill(' ') << "Mammal" ;
} // End print

// Mutator for nursing status
void Mammal::setNursing(int nursing) {
	// Set field nurse to passed in nursing value
	Nurse = nursing;
} // End setNursing

// Accessor for nursing status
int Mammal::getNursing() {
	// Return nursing status from field
	return Nurse;
} // End getNursing
