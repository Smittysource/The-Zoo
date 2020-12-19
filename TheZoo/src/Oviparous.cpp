/*
 * Oviparous.cpp
 *
  *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class definition for the class Oviparous derived from the class Animal.
 *
 */

#include "Oviparous.h"

// Default constructor
Oviparous::Oviparous() {
	// Initialize number of eggs to 0
	NumberOfEggs = 0;
} // End default constructor

// Returns a string with all of the oviparous animal's information in the same format it is in in the file
string Oviparous::toString() {
	// Return the output of Animal's toString with Oviparous and padding concatenated to it
	return Animal::toString() + "Oviparous" + padString(TYPE_LENGTH - 9);
} // End toString

// Print the animal's information to the screen
void Oviparous::print() {
	// Print Animal's data
	Animal::print();
	// Print Oviparous with padding
	cout << setw(TYPE_LENGTH + PADDING) << setfill(' ') << "Oviparous" ;
} // End print

// Mutator for number of eggs.
void Oviparous::setNumberOfEggs(int numEggs) {
	// Set number of eggs to input numEggs
	NumberOfEggs = numEggs;
} // End setNumberOfEggs

// Accessor for number of eggs.
int Oviparous::getNumberOfEggs() {
	// Return field NumberOfEggs
	return NumberOfEggs;
} // End getNumberOfEggs
