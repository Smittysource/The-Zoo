/*
 * Goose.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Goose derived from the class Oviparous.
 *
 */

#ifndef GOOSE_H_
#define GOOSE_H_

#include "Oviparous.h"

// Class Goose derived from class Oviparous
class Goose: public Oviparous {
public:
	// Declare member methods and fields
	Goose();					// Default Constructor
	string toString();			// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();				// Print the animal's information to the screen

	string type = "Goose";		// Sub-type of animal as string
}; // End class

#endif /* GOOSE_H_ */
