/*
 * Crocodile.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Crocodile derived from the class Oviparous.
 *
 */

#ifndef CROCODILE_H_
#define CROCODILE_H_

#include "Oviparous.h"

// Class Crocodile derived from class Oviparous
class Crocodile: public Oviparous {
public:
	// Declare member methods and fields
	Crocodile();							// Default Constructor
	string toString();						// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();							// Print the animal's information to the screen

	string type = "Crocodile";				// Sub-type of animal as string
}; // End class Crocodile

#endif /* CROCODILE_H_ */
