/*
 * Whale.h
 *
 *  David Smith
 *  CS 210
 *  December 9, 2020
 *
 *  This file contains the class declaration for the class Whale derived from the class Mammal.
 *
 */

#ifndef WHALE_H_
#define WHALE_H_

#include "Mammal.h"

// Class Whale derived from class Mammal
class Whale: public Mammal {
public:
	// Declare member methods and fields
	Whale();						// Default Constructor
	string toString();				// Returns a string with all of the mammal's information in the same format it is in in the file
	void print();					// Print the animal's information to the screen

	string type = "Whale";			// Sub-type of animal as string
}; // End class Whale

#endif /* WHALE_H_ */
